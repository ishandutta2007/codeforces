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
    vector<int> par, sz;
    vector<pair<int, int>> top;

    DSU(int n) : par(n), sz(n, 1), top(n) {
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

    int n;
    cin >> n;
    vector<int> c(n);
    vector<array<int, 3>> v;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            if (i == j)
                c[i] = a;
            else
                v.push_back({a, i, j});
        }

    sort(v.rbegin(), v.rend());
    vector<int> latest(n, -1);
    vector<pair<int, int>> ret;
    int r = -1;
    for (int i=0; i<(int)v.size(); ) {
        int j = i;
        DSU dsu(n);
        for (int u=0; u<n; u++)
            dsu.top[u] = {latest[u] == -1 ? INT_MAX : c[latest[u]], latest[u]};
        while (j < (int) v.size() && v[i][0] == v[j][0]) {
            dsu.unite(v[j][1], v[j][2]);
            j++;
        }
        map<int, vector<int>> mp;
        for (int u=0; u<n; u++)
            mp[dsu.find(u)].push_back(u);
        for (auto &p : mp) {
            if (p.second.size() == 1)
                continue;
            for (int u : p.second)
                latest[u] = (int) c.size();
            if (dsu.top[p.first].second == -1)
                r = (int) c.size();
            else
                ret.emplace_back((int) c.size(), dsu.top[p.first].second);
            c.push_back(v[i][0]);
        }
        i = j;
    }
    for (int u=0; u<n; u++) {
        assert(latest[u] != -1);
        ret.emplace_back(u, latest[u]);
    }

    assert((int) ret.size() == (int) c.size() - 1);
    cout << c.size() << "\n";
    for (int x : c)
        cout << x << " ";
    cout << "\n" << r + 1 << "\n";
    for (auto [u, v] : ret)
        cout << u + 1 << " " << v + 1 << "\n";

    return 0;
}