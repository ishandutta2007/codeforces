#include <bits/stdc++.h>
using namespace std;

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

struct SegmentTree {
    int n;
    vector<int> st;

    SegmentTree(int _n) : n(_n), st(2*n) {}

    int query(int l, int r) {
        int ret = 0;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret += st[l++];
            if (r&1) ret += st[--r];
        }
        return ret;
    }

    void update(int p, int val) {
        for (st[p+=n]=val; p>1; p>>=1)
            st[p>>1] = st[p] + st[p^1];
    }
};

int id, deg[100005];
pair<int, int> pos[100005], node[100005];
vector<pair<int, int>> adj[100005];
vector<SegmentTree> segs;

void dfs(int u, int p) {
    for (auto [v, i] : adj[u])
        if (v != p) {
            pos[i] = {segs.size(), id};
            node[v] = {segs.size(), id};
            id++;
            dfs(v, u);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    int mx = 0, r = -1;
    for (int i=0; i<n; i++)
        if (deg[i] > mx) {
            mx = deg[i];
            r = i;
        }

    for (auto [v, i] : adj[r]) {
        pos[i] = {segs.size(), 0};
        node[v] = {segs.size(), 0};
        id = 1;
        dfs(v, r);
        segs.emplace_back(id);
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int e;
            cin >> e;
            e--;
            segs[pos[e].first].update(pos[e].second, 0);
        } else if (t == 2) {
            int e;
            cin >> e;
            e--;
            segs[pos[e].first].update(pos[e].second, 1);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (a == b) {
                cout << "0\n";
            } else if (a == r || b == r) {
                if (b == r)
                    swap(a, b);
                cout << (segs[node[b].first].query(0, node[b].second + 1) == 0 ? node[b].second + 1 : -1) << "\n";
            } else if (node[a].first == node[b].first) {
                if (node[a].second > node[b].second)
                    swap(a, b);
                cout << (segs[node[a].first].query(node[a].second + 1, node[b].second + 1) == 0 ? node[b].second - node[a].second : -1) << "\n";
            } else {
                cout << (segs[node[a].first].query(0, node[a].second + 1) == 0 && segs[node[b].first].query(0, node[b].second + 1) == 0
                       ? node[a].second + node[b].second + 2 : -1) << "\n";
            }
        }
    }

    return 0;
}