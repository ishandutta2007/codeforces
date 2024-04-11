#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
const int mod = 1e9 + 7;
const int LOGN = 20;
int n;
int C[100005];
vector<int> A[100005];
vector<int> E[100005];
 
ll pw(ll x, ll p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    ll v = pw(x, p / 2);
    v = v * v % mod;
    if (p % 2 != 0) v = v * x % mod;
    return v;
}
 
int sz[100005];
int de[100005];
 
void dfs1(int x, int p) {
    sz[x] = 1;
    int dd = 0;
    for (int i = 0; i < LOGN; i++) {
        dd += (1 << i);
    }
    for (int i : E[x]) {
        if (i == p || de[i]) continue;
        dfs1(i, x);
        sz[x] += sz[i];
    }
}
 
int dfs2(int x, int p, int n) {
    int dd = 0;
    for (int i = 0; i < LOGN; i++) {
        dd += (1 << i);
    }
    for (int i : E[x]) {
        if (i == p || de[i]) continue;
        if (sz[i] > n / 2) return dfs2(i, x, n);
    }
    return x;
}
 
int D[100005][20];
int G[100005][20];
 
void dfs3(int x, int p, int s, int d, int g) {
    int dd = 0;
    for (int i = 0; i < LOGN; i++) {
        dd += (1 << i);
    }
    D[x][d] = s;
    G[x][d] = g;
    for (int i : E[x]) {
        if (i == p || de[i]) continue;
        dfs3(i, x, s + 1, d, g);
    }
}
 
int P[100005];
int L[100005];
ll csum[100005];
vector<ll> cisum[100005];
ll dsum[100005];
vector<ll> disum[100005];
int cent_decomp(int x, int d) {
    dfs1(x, 0);
    x = dfs2(x, 0, sz[x]);
    L[x] = d;
    D[x][d] = 0;
    G[x][d] = 0;
    cisum[x].push_back(0);
    disum[x].push_back(0);
    for (int i : E[x]) {
        if (de[i]) continue;
        dfs3(i, x, 1, d, cisum[x].size());
        cisum[x].push_back(0);
        disum[x].push_back(0);
    }
    de[x] = 1;
    for (int i : E[x]) {
        if (de[i]) continue;
        P[cent_decomp(i, d + 1)] = x;
    }
    return x;
}
 
ll query(int x, int t) {
    ll ans = 0;
    for (int c = x; c; c = P[c]) {
        int d = L[c];
        ll add = (ll)t * D[x][d] % mod;
        ans += (csum[c] + mod - cisum[c][G[x][d]]) * add % mod;
        ans += (dsum[c] + mod - disum[c][G[x][d]]) * t % mod;
        csum[c] = (csum[c] + t) % mod;
        cisum[c][G[x][d]] = (cisum[c][G[x][d]] + t) % mod;
        dsum[c] = (dsum[c] + add) % mod;
        disum[c][G[x][d]] = (disum[c][G[x][d]] + add) % mod;
    }
    return ans % mod;
}
 
int main() {
    scanf("%d", &n);
    ll all = 1;
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        A[l].push_back(i);
        A[r + 1].push_back(-i);
        all = all * (r - l + 1) % mod;
        C[i] = pw(r - l + 1, mod - 2);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    cent_decomp(1, 0);
    ll ans = 0, sum = 0;
    for (int i = 1; i <= 100000; i++) {
        for (int j : A[i]) {
            if (j < 0) {
                sum += query(-j, mod - C[-j]);
            }
            else {
                sum += query(j, C[j]);
            }
        }
        sum %= mod;
        ans += sum;
        ans %= mod;
    }
    printf("%lld\n", ans * all % mod);
}