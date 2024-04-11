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

long long pref[200005], fact[15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i=1; i<=n; i++)
        pref[i] = pref[i-1] + i;
    fact[0] = 1;
    for (int i=1; i<15; i++)
        fact[i] = fact[i-1] * i;

    long long x0 = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l-1] << "\n";
        } else {
            int x;
            cin >> x;
            x0 += x;
            vector<bool> vis(15);
            long long cur = x0;
            for (int i=max(n-14, 1); i<=n; i++) {
                int idx = cur / fact[n-i], pos = 0;
                while (vis[pos])
                    pos++;
                while (idx--) {
                    pos++;
                    while (vis[pos])
                        pos++;
                }
                pref[i] = pref[i-1] + pos + 1 + max(n - 15, 0);
                vis[pos] = true;
                cur %= fact[n-i];
            }
        }
    }

    return 0;
}