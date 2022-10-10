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

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
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
        vector<vector<array<int, 3>>> segs(2);
        vector<int> compress;
        for (int i=0; i<n; i++) {
            int c, l, r;
            cin >> c >> l >> r;
            segs[c].push_back({l, r, i});
            compress.push_back(l);
        }

        sort(compress.begin(), compress.end());
        compress.erase(unique(compress.begin(), compress.end()), compress.end());
        int o = (int) compress.size();

        auto get = [&] (int x) -> int {
            return int(upper_bound(compress.begin(), compress.end(), x) - compress.begin()) - 1;
        };

        DSU dsu(n + 8 * o);
        for (int rep=0; rep<2; rep++) {
            vector<vector<int>> stuff(4 * o);

            auto red = [&] (auto &self, int p, int l, int r, int i, int k) -> void {
                if (stuff[p].empty())
                    stuff[p].push_back(n + p + 4 * o * rep);
                stuff[p].push_back(k);
                if (l == r)
                    return;
                int m = (l + r) / 2;
                if (i <= m)
                    self(self, 2 * p, l, m, i, k);
                else
                    self(self, 2 * p + 1, m + 1, r, i, k);
            };

            auto blue = [&] (auto &self, int p, int l, int r, int i, int j, int k) -> void {
                if (i > r || j < l)
                    return;
                if (i <= l && r <= j) {
                    if (!stuff[p].empty()) {
                        for (int x : stuff[p])
                            dsu.unite(x, k);
                        stuff[p] = {n + p + 4 * o * rep};
                    }
                    return;
                }
                int m = (l + r) / 2;
                self(self, 2 * p, l, m, i, j, k);
                self(self, 2 * p + 1, m + 1, r, i, j, k);
            };

            for (auto [l, r, i] : segs[0])
                red(red, 1, 0, o - 1, get(l), i);
            for (auto [l, r, i] : segs[1])
                blue(blue, 1, 0, o - 1, get(l), get(r), i);
            swap(segs[0], segs[1]);
        }

        set<int> comps;
        for (int i=0; i<n; i++)
            comps.insert(dsu.find(i));
        cout << comps.size() << "\n";
    }

    return 0;
}