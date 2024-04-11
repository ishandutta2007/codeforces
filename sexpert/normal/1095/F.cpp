    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    const int MAXN = 2e5 + 2;
    const ll INF = 1e18;
     
    struct edge {
        int u, v;
        ll w;
        edge(int u, int v, ll w) : u(u), v(v), w(w){}
     
        bool operator< (const edge& o) {
            return w < o.w;
        }
    };
     
    vector<edge> edges;
    int par[MAXN], rnk[MAXN];
     
    int find(int x) {
        return (par[x] == 0 ? x : par[x] = find(par[x]));
    }
     
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            if(rnk[x] < rnk[y])
                swap(x, y);
            par[y] = x;
            if(rnk[x] == rnk[y])
                rnk[x]++;
        }
    }
     
    ll kruskal() {
        ll ans = 0;
        sort(edges.begin(), edges.end());
        for(auto e : edges) {
            if(find(e.u) != find(e.v)) {
                join(e.u, e.v);
                ans += e.w;
            }
        }
        return ans;
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n, m;
        ll a[MAXN];
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            edges.push_back(edge(u, v, w));
        }
        int v = 0;
        ll mn = INF;
        for(int i = 0; i < n; i++) {
            if(a[i] < mn) {
                mn = a[i];
                v = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i == v)
                continue;
            edges.push_back(edge(v + 1, i + 1, a[v] + a[i]));
        }
        cout << kruskal() << endl;
    }