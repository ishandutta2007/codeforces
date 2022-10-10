#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int MAXN = 3e5 + 5;
const int SZ = 550;
const int MOD = 1e9 + 9;

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int a[MAXN], fib[MAXN], pref[MAXN], cur[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        add(a[i], a[i-1]);
    }

    fib[1] = fib[2] = pref[1] = 1;
    pref[2] = 2;
    for (int i=3; i<=n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        pref[i] = (pref[i-1] + fib[i]) % MOD;
    }

    vector<pair<int, int>> updates;
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            updates.emplace_back(l, r);
        } else {
            int ret = (a[r] - a[l-1] + MOD) % MOD;
            for (auto &p : updates) {
                int il = max(p.first, l), ir = min(p.second, r);
                if (il <= ir) {
                    add(ret, pref[ir - p.first + 1]);
                    sub(ret, pref[il - p.first]);
                }
            }
            cout << ret << "\n";
        }
        if (m % SZ == 0) {
            memset(cur, 0, sizeof(cur));
            for (auto &p : updates) {
                add(cur[p.first], 1);
                sub(cur[p.second + 1], fib[p.second - p.first + 2]);
                sub(cur[p.second + 2], fib[p.second - p.first + 1]);
            }
            updates.clear();
            int sum = 0;
            for (int i=1; i<=n; i++) {
                if (i >= 2)
                    add(cur[i], cur[i-2]);
                add(cur[i], cur[i-1]);
                add(sum, cur[i]);
                add(a[i], sum);
            }
        }
    }

    return 0;
}