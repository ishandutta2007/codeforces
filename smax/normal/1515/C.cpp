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
        int n, m, x;
        cin >> n >> m >> x;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for (int i=0; i<n; i++) {
        //     int h;
        //     cin >> h;
        //     pq.emplace(h, i);
        // }

        // DSU dsu(n);
        // while ((int) pq.size() > m) {
        //     auto [h1, i1] = pq.top();
        //     pq.pop();
        //     auto [h2, i2] = pq.top();
        //     pq.pop();
        //     DEBUG(h1, h2, i1, i2);
        //     dsu.unite(i1, i2);
        //     pq.emplace(h1 + h2, dsu.find(i1));
        // }

        // int mn = INT_MAX, mx = INT_MIN;
        // while (!pq.empty()) {
        //     auto [h, i] = pq.top();
        //     pq.pop();
        //     mn = min(mn, h);
        //     mx = max(mx, h);
        // }
        // DEBUG(mn, mx);
        // if (mx - mn > x) {
        //     cout << "NO\n";
        //     continue;
        // }

        // cout << "YES\n";
        // int id = 1;
        // vector<int> vis(n);
        // for (int i=0; i<n; i++) {
        //     if (!vis[dsu.find(i)])
        //         vis[dsu.find(i)] = id++;
        //     cout << vis[dsu.find(i)] << " ";
        // }
        // cout << "\n";

        vector<pair<int, int>> h(n);
        for (int i=0; i<n; i++) {
            cin >> h[i].first;
            h[i].second = i;
        }

        sort(h.begin(), h.end());
        vector<int> ret(n);
        for (int i=0; i<n; i++)
            ret[h[i].second] = i % m;

        cout << "YES\n";
        for (int y : ret)
            cout << y + 1 << " ";
        cout << "\n";
    }

    return 0;
}