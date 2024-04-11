#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 100005
#define SZ 317

int cnt[SZ][MAXN];
vector<int> v[SZ];

void update(int l, int r) {
    if (l == r)
        return;

    int idx = 0, val;
    for (int i=0; i<SZ; i++) {
        if (idx + v[i].size() >= r) {
            r -= idx;
            val = v[i][r-1];
            cnt[i][val]--;
            v[i].erase(v[i].begin() + r - 1);
            break;
        }
        idx += v[i].size();
    }

    idx = 0;
    for (int i=0; i<SZ; i++) {
        if (idx + v[i].size() >= l) {
            l -= idx;
            cnt[i][val]++;
            v[i].insert(v[i].begin() + l - 1, val);
            break;
        }
        idx += v[i].size();
    }
}

int query(int p, int k) {
    int idx = 0, ret = 0;
    for (int i=0; i<SZ; i++) {
        if (idx + v[i].size() >= p) {
            p -= idx;
            for (int j=0; j<p; j++)
                ret += (v[i][j] == k);
            break;
        }
        ret += cnt[i][k];
        idx += v[i].size();
    }
    return ret;
}

void rebuild() {
    for (int i=0; i<SZ; i++)
        if (v[i].size() > SZ) {
            assert(i < SZ - 1);
            for (int j=SZ; j<v[i].size(); j++) {
                cnt[i][v[i][j]]--;
                cnt[i+1][v[i][j]]++;
            }
            v[i+1].insert(v[i+1].begin(), v[i].begin() + SZ, v[i].end());
            v[i].erase(v[i].begin() + SZ, v[i].end());
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cnt[i / SZ][a]++;
        v[i / SZ].push_back(a);
    }

    int q, ret = 0, ops = 0;
    cin >> q;
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l = (l + ret - 1) % n + 1;
        r = (r + ret - 1) % n + 1;
        if (l > r)
            swap(l, r);

        if (type == 1) {
            update(l, r);
            ops++;
            if (ops == SZ) {
                rebuild();
                ops = 0;
            }
        } else {
            int k;
            cin >> k;
            k = (k + ret - 1) % n + 1;
            cout << (ret = query(r, k) - query(l-1, k)) << "\n";
        }
    }

    return 0;
}