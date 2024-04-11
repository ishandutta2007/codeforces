#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct DSU {
    gp_hash_table<int, int, custom_hash> par, sz;
};

int findRoot(DSU *ds, int u) {
    if (u != ds->par[u])
        ds->par[u] = findRoot(ds, ds->par[u]);
    return ds->par[u];
}

bool unite(DSU *ds, int u, int v) {
    u = findRoot(ds, u);
    v = findRoot(ds, v);
    if (u == v)
        return false;
    if (ds->sz[u] < ds->sz[v])
        swap(u, v);
    ds->par[v] = u;
    ds->sz[u] += ds->sz[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> queries, rev;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i=0; i<q; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        queries.emplace_back(x, y, c);
        rev.emplace_back(x, y, grid[x][y]);
        grid[x][y] = c;
    }

    auto get = [&] (int r, int c) {
        return r * m + c;
    };

    auto ok = [&] (int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;
    };

    gp_hash_table<int, DSU*, custom_hash> ds;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            int idx = get(i, j);
            if (ds.find(grid[i][j]) == ds.end())
                ds[grid[i][j]] = new DSU();
            ds[grid[i][j]]->par[idx] = idx;
            ds[grid[i][j]]->sz[idx] = 1;
            if (i > 0 && grid[i-1][j] == grid[i][j])
                unite(ds[grid[i][j]], idx, get(i - 1, j));
            if (j > 0 && grid[i][j-1] == grid[i][j])
                unite(ds[grid[i][j]], idx, get(i, j - 1));
        }
    vector<int> rem(q);
    reverse(rev.begin(), rev.end());
    for (int i=0; i<q; i++) {
        auto [x, y, c] = rev[i];
        if (grid[x][y] == c)
            continue;
        int idx = get(x, y);
        ds[grid[x][y]]->par.erase(idx);
        ds[grid[x][y]]->sz.erase(idx);
        if (ds[grid[x][y]]->par.empty()) {
            delete ds[grid[x][y]];
            ds.erase(grid[x][y]);
        }
        grid[x][y] = c;
        if (ds.find(c) == ds.end())
            ds[c] = new DSU();
        ds[c]->par[idx] = idx;
        ds[c]->sz[idx] = 1;
        rem[q - i - 1]--;
        for (int d=0; d<4; d++) {
            int nr = x + dr[d], nc = y + dc[d];
            if (ok(nr, nc) && grid[nr][nc] == grid[x][y] && unite(ds[c], idx, get(nr, nc)))
                rem[q - i - 1]++;
        }
    }

    int comp = 1;
    for (int i=0; i<q; i++) {
        auto [x, y, c] = queries[i];
        if (grid[x][y] == c) {
            cout << comp << "\n";
            continue;
        }
        int idx = get(x, y);
        comp += rem[i];
        ds[grid[x][y]]->par.erase(idx);
        ds[grid[x][y]]->sz.erase(idx);
        if (ds[grid[x][y]]->par.empty()) {
            delete ds[grid[x][y]];
            ds.erase(grid[x][y]);
        }
        grid[x][y] = c;
        if (ds.find(c) == ds.end())
            ds[c] = new DSU();
        ds[c]->par[idx] = idx;
        ds[c]->sz[idx] = 1;
        comp++;
        for (int d=0; d<4; d++) {
            int nr = x + dr[d], nc = y + dc[d];
            if (ok(nr, nc) && grid[nr][nc] == grid[x][y] && unite(ds[c], idx, get(nr, nc)))
                comp--;
        }
        cout << comp << "\n";
    }

    return 0;
}