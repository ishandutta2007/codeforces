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

struct SCC {
    int n, ti;
    vector<int> num, id, stk;
    vector<vector<int>> adj, dag, comp;

    SCC(int _n) : n(_n), ti(0), num(n), id(n, -1), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void init() {
        for (int u=0; u<n; u++)
            if (!num[u])
                dfs(u);
        dag.resize(comp.size());
        for (auto &c : comp)
            for (int u : c)
                for (int v : adj[u])
                    if (id[u] != id[v])
                        dag[id[u]].push_back(id[v]);
        for (auto &v : dag) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }

    int dfs(int u) {
        int low = num[u] = ++ti;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!num[v])
                low = min(low, dfs(v));
            else if (id[v] == -1)
                low = min(low, num[v]);
        }
        if (low == num[u]) {
            comp.emplace_back();
            do {
                id[stk.back()] = (int) comp.size() - 1;
                comp.back().push_back(stk.back());
                stk.pop_back();
            } while (comp.back().back() != u);
        }
        return low;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        SCC scc(n);
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            scc.addEdge(a, b);
        }

        scc.init();
        if (scc.comp.size() == 1) {
            cout << "No\n";
            continue;
        }

        vector<bool> human(n);
        cout << "Yes\n" << scc.comp[0].size() << " " << n - scc.comp[0].size() << "\n";
        for (int x : scc.comp[0]) {
            cout << x + 1 << " ";
            human[x] = true;
        }
        cout << "\n";
        for (int i=0; i<n; i++)
            if (!human[i])
                cout << i + 1 << " ";
        cout << "\n";
    }

    return 0;
}