#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 5;

int start[MAXN], mana[MAXN], rate[MAXN], tMin[4 * MAXN], tMax[4 * MAXN], firstMin[4 * MAXN], firstMax[4 * MAXN], lazy[4 * MAXN];
vector<pair<int, int>> ponies[4 * MAXN][2];
vector<long long> pref[4 * MAXN][2], suff[4 * MAXN][2], sumStart[4 * MAXN];

void build(int p, int l, int r) {
    lazy[p] = -1;
    firstMin[p] = firstMax[p] = 1;
    if (l == r) {
        ponies[p][0] = {{rate[l] == 0 ? INF : mana[l] / rate[l], l}};
        ponies[p][1] = {{rate[l] == 0 ? INF : (mana[l] - start[l]) / rate[l], l}};
        pref[p][0] = pref[p][1] = {mana[l]};
        suff[p][0] = suff[p][1] = {rate[l]};
        sumStart[p] = {start[l]};
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    for (int k=0; k<2; k++) {
        merge(ponies[2*p][k].begin(), ponies[2*p][k].end(), ponies[2*p+1][k].begin(), ponies[2*p+1][k].end(), back_inserter(ponies[p][k]));
        for (int i=0; i<(int)ponies[p][k].size(); i++)
            pref[p][k].push_back(mana[ponies[p][k][i].second] + (pref[p][k].empty() ? 0 : pref[p][k].back()));
        suff[p][k].resize(ponies[p][k].size());
        if (k == 1) sumStart[p].resize(ponies[p][k].size());
        for (int i=(int)ponies[p][k].size()-1; i>=0; i--) {
            suff[p][k][i] = rate[ponies[p][k][i].second] + (i + 1 < (int) ponies[p][k].size() ? suff[p][k][i+1] : 0);
            if (k == 1) sumStart[p][i] = start[ponies[p][k][i].second] + (i + 1 < (int) ponies[p][k].size() ? sumStart[p][i+1] : 0);
        }
    }
}

void push(int p, bool leaf) {
    if (lazy[p] != -1) {
        tMin[p] = tMax[p] = lazy[p];
        firstMin[p] = firstMax[p] = 0;
        if (!leaf) lazy[2*p] = lazy[2*p+1] = lazy[p];
        lazy[p] = -1;
    }
}

long long query(int p, int l, int r, int i, int j, int t) {
    push(p, l == r);
    if (i > r || j < l)
        return 0;
    if (i <= l && r <= j && tMin[p] == tMax[p] && firstMin[p] == firstMax[p]) {
        int pos = int(lower_bound(ponies[p][firstMin[p]].begin(), ponies[p][firstMin[p]].end(), make_pair(t - tMin[p], 0)) - ponies[p][firstMin[p]].begin());
        long long ret = (pos > 0 ? pref[p][firstMin[p]][pos-1] : 0) + (pos < (int) ponies[p][firstMin[p]].size() ? suff[p][firstMin[p]][pos] * (t - tMin[p]) + (firstMin[p] ? sumStart[p][pos] : 0) : 0);
        lazy[p] = t;
        push(p, l == r);
        return ret;
    }
    int m = (l + r) / 2;
    long long ret = query(2 * p, l, m, i, j, t) + query(2 * p + 1, m + 1, r, i, j, t);
    tMin[p] = min(tMin[2*p], tMin[2*p+1]);
    tMax[p] = max(tMax[2*p], tMax[2*p+1]);
    firstMin[p] = min(firstMin[2*p], firstMin[2*p+1]);
    firstMax[p] = max(firstMax[2*p], firstMax[2*p+1]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> start[i] >> mana[i] >> rate[i];

    build(1, 0, n - 1);
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        assert(t > 0);  // t = 0?
        l--, r--;
        cout << query(1, 0, n - 1, l, r, t) << "\n";
    }

    return 0;
}