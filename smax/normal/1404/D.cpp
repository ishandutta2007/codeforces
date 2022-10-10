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

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "First\n";
        for (int i=1; i<=n; i++)
            cout << i << " ";
        for (int i=1; i<=n; i++)
            cout << i << " ";
        cout << endl;

        int ret;
        cin >> ret;
        assert(ret == 0);
    } else {
        cout << "Second" << endl;

        vector<pair<int, int>> pairs(n);
        for (int i=1; i<=2*n; i++) {
            int p;
            cin >> p;
            p--;
            if (pairs[p].first)
                pairs[p].second = i;
            else
                pairs[p].first = i;
        }

        vector<vector<pair<int, int>>> adj(n);
        for (int i=0; i<n; i++) {
            auto [u, v] = pairs[i];
            adj[u % n].emplace_back(v % n, i);
            adj[v % n].emplace_back(u % n, i);
        }

        long long sum = 0;
        vector<bool> vis(n);

        auto dfs = [&] (auto &self, int u, int p) -> void {
            if (vis[u])
                return;
            vis[u] = true;
            for (auto [v, i] : adj[u])
                if (i != p) {
                    if (pairs[i].first % n != u)
                        swap(pairs[i].first, pairs[i].second);
                    sum += pairs[i].first;
                    self(self, v, i);
                    return;
                }
        };

        for (int u=0; u<n; u++)
            if (!vis[u])
                dfs(dfs, u, -1);

        if (sum % (2 * n) != 0)
            for (auto &p : pairs)
                swap(p.first, p.second);
        for (const auto &p : pairs)
            cout << p.first << " ";
        cout << endl;

        int ret;
        cin >> ret;
        assert(ret == 0);
    }

    return 0;
}