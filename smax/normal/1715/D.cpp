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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> constr;
    for (int i=0; i<q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l > r) swap(l, r);
        constr.push_back({l, r, x});
    }

    vector<int> ret(n);
    for (int i=0; i<30; i++) {
        vector<vector<pair<int, bool>>> adj(n);
        vector<bool> ban(n), need(n);
        for (auto [l, r, x] : constr) {
            adj[l].emplace_back(r, x >> i & 1);
            if (~x >> i & 1)
                ban[l] = ban[r] = true;
        }
        for (int u=0; u<n; u++) {
            if (need[u]) {
                assert(!ban[u]);
                ret[u] |= 1 << i;
            } else {
                bool has0 = false, has1 = false;
                for (auto [v, w] : adj[u])
                    if (w == 1) {
                        has0 |= ban[v] || u == v;
                        has1 = true;
                    }
                if (has1) {
                    if (has0)
                        ret[u] |= 1 << i;
                    else
                        for (auto [v, w] : adj[u])
                            if (w == 1)
                                need[v] = true;
                }
            }
        }
    }

    for (int x : ret)
        cout << x << " ";
    cout << "\n";

    return 0;
}