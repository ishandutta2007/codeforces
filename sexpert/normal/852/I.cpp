#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MAXN = 1e5 + 19;
const int LOG = 18;
int cnt[2*MAXN + 5], num[2*MAXN + 5], h[MAXN], st[MAXN], en[MAXN], mul[MAXN], val[MAXN], odfs[2*MAXN], up[MAXN][LOG], k, tdfs, cL, cR;
ll cur, ans[MAXN];
vector<int> adj[MAXN];
map<int, int> compress;

struct query {
    int L, R, idx, extra;
    bool operator<(const query &o) const {
        return make_pair(L/k, R) < make_pair(o.L/k, o.R);
    }
};

vector<query> qs;

void dfs(int s, int p = 1) {
    up[s][0] = p;
    h[s] = (s == 1 ? 0 : h[p] + 1);
    for(int l = 0; l < LOG - 1; l++)
        up[s][l + 1] = up[up[s][l]][l];
    st[s] = ++tdfs;
    odfs[tdfs] = s;
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
    en[s] = ++tdfs;
    odfs[tdfs] = s;
}

int lca(int u, int v) {
    if(h[u] < h[v])
        swap(u, v);
    int diff = h[u] - h[v];
    for(int l = LOG - 1; l >= 0; l--)
        if(diff & (1 << l)) u = up[u][l];
    if(u == v) return u;
    for(int l = LOG - 1; l >= 0; l--) {
        if(up[u][l] != up[v][l]) {
            u = up[u][l];
            v = up[v][l];
        }
    }
    return up[u][0];
}

inline void addL() {
    int v = odfs[cL];
    if(num[v] == 1) {
        cur -= cnt[2*MAXN - val[v]];
        cnt[val[v]]--;
    }
    num[v]--;
    if(num[v] == 1) {
        cur += cnt[2*MAXN - val[v]];
        cnt[val[v]]++;
    }
    cL++;
}

inline void subL() {
    cL--;
    int v = odfs[cL];
    if(num[v] == 1) {
        cur -= cnt[2*MAXN - val[v]];
        cnt[val[v]]--;
    }
    num[v]++;
    if(num[v] == 1) {
        cur += cnt[2*MAXN - val[v]];
        cnt[val[v]]++;
    }
}

inline void addR() {
    cR++;
    int v = odfs[cR];
    if(num[v] == 1) {
        cur -= cnt[2*MAXN - val[v]];
        cnt[val[v]]--;
    }
    num[v]++;
    if(num[v] == 1) {
        cur += cnt[2*MAXN - val[v]];
        cnt[val[v]]++;
    }
}

inline void subR() {
    int v = odfs[cR];
    if(num[v] == 1) {
        cur -= cnt[2*MAXN - val[v]];
        cnt[val[v]]--;
    }
    num[v]--;
    if(num[v] == 1) {
        cur += cnt[2*MAXN - val[v]];
        cnt[val[v]]++;
    }
    cR--;
}

void mo() {
    sort(qs.begin(), qs.end());
    cL = 1;
    cR = 1;
    num[1]++;
    cnt[val[1]]++;
    for(auto q : qs) {
        //cout << q.L << " " << q.R << " " << q.idx << endl;
        while(cL < q.L) addL();
        while(cL > q.L) subL();
        while(cR < q.R) addR();
        while(cR > q.R) subR();
        ll res = cur;
        if(q.extra != -1)
            res += cnt[2*MAXN - val[q.extra]];
        ans[q.idx] = res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    k = sqrt(n);
    for(int i = 1; i <= n; i++)
        cin >> mul[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(!compress.count(x))
            compress[x] = ++cnt;
        val[i] = (mul[i] ? compress[x] : 2*MAXN - compress[x]);
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if(st[u] > st[v])
            swap(u, v);
        int l = lca(u, v);
        if(l == u)
            qs.push_back({st[u], st[v], i, -1});
        else
            qs.push_back({en[u], st[v], i,  l});
    }
    mo();
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}