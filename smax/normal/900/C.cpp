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

#define MAXN 100001

int n, bit[MAXN];

int query(int x) {
    int ret = 0;
    for (int i=x; i>0; i-=i&-i)
        ret += bit[i];
    return ret;
}

void update(int x) {
    for (int i=x; i<=n; i+=i&-i)
        bit[i]++;
}

int p[MAXN], where[MAXN], bigger[MAXN], cnt[MAXN];
bool isRecord[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        where[p[i]] = i + 1;
    }

    int mx = 0, numRecords = 0;
    for (int i=0; i<n; i++) {
        if (p[i] > mx) {
            isRecord[p[i]] = true;
            numRecords++;
            mx = p[i];
        } else {
            bigger[p[i]] = mx;
        }
    }

    for (int i=n; i>0; i--) {
        if (query(where[i]) == 1)
            cnt[bigger[i]]++;
        update(where[i]);
    }

    pair<int, int> best(-1, -1);
    for (int i=1; i<=n; i++)
        best = max(best, {numRecords - isRecord[i] + cnt[i], -i});

    cout << -best.second << "\n";

    return 0;
}