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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct LCA {
    vector<int> in, out, depth, path, ret;
    vector<vector<int>> adj;
    RMQ<int> rmq;

    LCA(int n) : in(n), out(n), depth(n), adj(n), rmq({}) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = 0) {
        dfs(r, -1);
        rmq = RMQ<int>(ret);
    }

    void dfs(int u, int p) {
        in[u] = (int) path.size();
        path.push_back(u);
        ret.push_back(in[u]);
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                path.push_back(u);
                ret.push_back(in[u]);
            }
        out[u] = (int) path.size();
    }

    int lca(int u, int v) {
        if (in[u] > in[v])
            swap(u, v);
        return path[rmq.query(in[u], in[v])];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool anc(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i=1; i<n; i++) {
            int a;
            cin >> a;
            a--;
            adj[a].push_back(i);
        }
        LCA lca(n);
        for (int i=1; i<n; i++) {
            int b;
            cin >> b;
            b--;
            lca.addEdge(i, b);
        }

        auto cmp = [&] (int u, int v) -> bool {
            return lca.in[u] < lca.in[v];
        };

        lca.init();
        int ret = 0;
        set<int> st;
        set<int, decltype(cmp)> st2(cmp), rem(cmp);

        auto add = [&] (int u) -> void {
            if (rem.count(u))
                rem.erase(u);
            // check if u is ancestor of some other node
            auto it = st.insert(lca.in[u]).first;
            if (next(it) != st.end() && *next(it) <= lca.out[u]) {
                st.erase(it);
                rem.insert(u);
            } else {
                // check if some other node is ancestor of u
                auto it2 = st2.insert(u).first;
                if (it2 != st2.begin() && lca.out[*prev(it2)] >= lca.in[u]) {
                    st.erase(lca.in[*prev(it2)]);
                    rem.insert(*prev(it2));
                    st2.erase(prev(it2));
                }
            }
        };

        auto dfs = [&] (auto &self, int u, int p) -> void {
            add(u);
            ret = max(ret, (int) st.size());
            for (int v : adj[u])
                if (v != p)
                    self(self, v, u);
            auto it = st.find(lca.in[u]);
            if (it != st.end()) {
                st.erase(it);
                auto it2 = st2.find(u);
                assert(it2 != st2.end());
                st2.erase(it2);
                // try to add in node above
                auto it3 = rem.lower_bound(u);
                if (it3 != rem.begin() && lca.anc(*prev(it3), u))
                    add(*prev(it3));
            } else {
                rem.erase(u);
            }
        };

        dfs(dfs, 0, -1);
        cout << ret << "\n";
    }

    return 0;
}