#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 200050, M = N;
const int mod = (int)1e9 + 7;
int n;

int a[N];

bool p[M];
ll mu[M], pm[M], phi[M], pms;
ll inv[M];

void sieve(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    mu[1] = 1;
    phi[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                phi[i * pm[j]] = phi[i] * pm[j];
                break;
            }
            mu[i * pm[j]] = -mu[i];
            phi[i * pm[j]] = phi[i] * (pm[j] - 1);
        }
    }
}

set<int> G[N];
vector<int> divs[N];
int par[N], sub[N];
ll f[N], g[N], sumphi[N];

int dfs1(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p)
            sub[v] += dfs1(nxt, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(int nxt : G[v]){
        if(nxt != p && sub[nxt] > nn/2) return dfs2(nxt, v, nn);
    }
    return v;
}

void dfs_add(int v, int p, int ad) {
    for(int x : divs[a[v]]) {
        sumphi[x] += ad * phi[a[v]];
        sumphi[v] %= mod;
    }
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs_add(nxt, v, ad);
    }
}

void dfs_cumu(int v, int p, int dep) {
    for(int i : divs[a[v]]) {
        g[i] += 1LL * phi[a[v]] * dep % mod * sumphi[i];
        g[i] %= mod;
    }
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs_cumu(nxt, v, dep + 1);
    }
}

void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    par[centroid] = p;
    dfs_add(centroid, -1, 1);
    for(int nxt : G[centroid]) {
        dfs_add(nxt, centroid, -1);
        dfs_cumu(nxt, centroid, 1);
        dfs_add(nxt, centroid, 1);
    }
    dfs_add(centroid, -1, -1);
    for(int nxt : G[centroid]){
        G[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    G[centroid].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = i; j <= n; j += i) divs[j].push_back(i);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    decompose(0, -1);
    for(int i = 1; i <= n; i++) {
        for(int d = 1; i * d <= n; d++) {
            f[i] += mu[d] * g[i * d];
            f[i] %= mod;
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += f[i] * i % mod * inv[phi[i]] % mod;
        res %= mod;
    }
    res *= inv[n] * inv[n-1] * 2 % mod;
    res = (res % mod + mod) % mod;
    cout << res << endl;

}