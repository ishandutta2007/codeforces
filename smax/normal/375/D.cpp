#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 100005
#define SZ 317

struct Query {
    int l, r, k, idx;

    bool operator < (const Query &other) const {
        if (l / SZ == other.l / SZ)
            return r < other.r;
        return l / SZ < other.l / SZ;
    }
};

int c[MAXN], sz[MAXN], where[MAXN], ret[MAXN], cnt[MAXN], ans[MAXN];
vector<int> preorder, adj[MAXN];
Query queries[MAXN];

int dfs(int u, int p) {
    sz[u] = 1;
    where[u] = preorder.size();
    preorder.push_back(c[u]);
    for (int v : adj[u])
        if (v != p)
            sz[u] += dfs(v, u);
    return sz[u];
}

void add(int i) {
    ans[++cnt[preorder[i]]]++;
}

void rem(int i) {
    ans[cnt[preorder[i]]--]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> c[i];
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    for (int i=0; i<m; i++) {
        int v, k;
        cin >> v >> k;
        v--;
        queries[i] = {where[v], where[v] + sz[v] - 1, k, i};
    }

    sort(queries, queries + m);
    int moLeft = 0, moRight = -1;
    for (int i=0; i<m; i++) {
        while (moLeft < queries[i].l)
            rem(moLeft++);
        while (moLeft > queries[i].l)
            add(--moLeft);
        while (moRight < queries[i].r)
            add(++moRight);
        while (moRight > queries[i].r)
            rem(moRight--);
        ret[queries[i].idx] = ans[queries[i].k];
    }

    for (int i=0; i<m; i++)
        cout << ret[i] << "\n";

    return 0;
}