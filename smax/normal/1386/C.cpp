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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct DSU {
    bool bipartite;
    vector<int> par, sz;
    vector<bool> color;
    vector<tuple<int, bool, bool>> stk;

    DSU(int n) : bipartite(true), par(n), sz(n, 1), color(n) {
        iota(par.begin(), par.end(), 0);
    }

    pair<int, bool> find(int u) {
        pair<int, bool> ret(u, color[u]);
        if (u != par[u]) {
            auto p = find(par[u]);
            ret.first = p.first;
            ret.second ^= p.second;
        }
        return ret;
    }

    bool same(int u, int v) {
        return find(u).first == find(v).first;
    }

    void unite(int u, int v) {
        bool x, y;
        tie(u, x) = find(u);
        tie(v, y) = find(v);
        if (u == v) {
            stk.emplace_back(-1, false, bipartite);
            bipartite &= x != y;
            return;
        }
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        stk.emplace_back(v, color[v], bipartite);
        color[v] = x ^ y ^ 1;
    }

    void undo() {
        auto [u, c, b] = stk.back();
        stk.pop_back();
        bipartite = b;
        if (u != -1) {
            sz[par[u]] -= sz[u];
            par[u] = u;
            color[u] = c;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> u(m), v(m);
    for (int i=0; i<m; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }

    DSU dsu(n);
    vector<array<int, 3>> stk;
    int block = 0;

    auto push = [&] (int a, int b) -> void {
        dsu.unite(a, b);
        stk.push_back({a, b, 0});
    };

    auto pop = [&] () -> void {
        assert(!stk.empty());
        if (block == 0) {
            for (int i=0; i<(int)stk.size(); i++)
                dsu.undo();
            reverse(stk.begin(), stk.end());
            for (auto &v : stk) {
                v[2] = 1;
                dsu.unite(v[0], v[1]);
            }
            block = (int) stk.size();
        }
        if (stk.back()[2] == 1) {
            dsu.undo();
            stk.pop_back();
            block--;
            return;
        }
        int x = block & -block;
        vector<array<int, 3>> blue, red;
        while (stk.back()[2] == 0) {
            dsu.undo();
            blue.push_back(stk.back());
            stk.pop_back();
        }
        for (int i=0; i<x; i++) {
            dsu.undo();
            red.push_back(stk.back());
            stk.pop_back();
        }
        for (int i=(int)blue.size()-1; i>=0; i--) {
            dsu.unite(blue[i][0], blue[i][1]);
            stk.push_back(blue[i]);
        }
        for (int i=(int)red.size()-1; i>0; i--) {
            dsu.unite(red[i][0], red[i][1]);
            stk.push_back(red[i]);
        }
        block--;
    };

    u.insert(u.end(), u.begin(), u.end());
    v.insert(v.end(), v.begin(), v.end());
    vector<int> reach(2 * m);
    for (int i=0, j=0; i<2*m; i++) {
        push(u[i], v[i]);
        while (!dsu.bipartite) {
            j++;
            pop();
        }
        reach[i] = j;
    }

    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (reach[m + l - 1] > r + 1 ? "YES" : "NO") << "\n";
    }

    return 0;
}