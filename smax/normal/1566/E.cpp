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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int init = 0;
        bool hasBud = false;
        vector<bool> leaf(n), bud(n), noooo(n);

        auto dfs = [&] (auto &self, int u, int p) -> int {
            if (adj[u].size() == 1 && u != 0) {
                init++;
                leaf[u] = true;
                return 0;
            } else {
                bool isBud = false;
                int ret = 0;
                for (int v : adj[u])
                    if (v != p) {
                        ret += self(self, v, u);
                        isBud |= leaf[v];
                    }
                if (isBud) {
                    hasBud = true;
                    bud[u] = true;
                    return ret + 1;
                }
                leaf[u] = true;
                for (int v : adj[u])
                    if (v != p && bud[v])
                        noooo[v] = true;
                return ret - 1;
            }
        };

        bool pog = false;
        vector<pair<int, int>> all;
        for (int v : adj[0]) {
            hasBud = false;
            all.emplace_back(dfs(dfs, v, 0), v);
            pog |= leaf[v];
            // if (hasBud) {
            //     // can do some excavation in all[0]

            // }
        }
        DEBUG(adj[0], all);
        sort(all.begin(), all.end());
        for (int i=!pog; i<(int)all.size(); i++)
            init -= all[i].first;
        if (pog) {
            cout << init << "\n";
            continue;
        }

        // you have something sticking off from all[0], we can do most of all[0] except for moving the final bud
        cout << init - all[0].first + 1 << "\n";
    }

    return 0;
}