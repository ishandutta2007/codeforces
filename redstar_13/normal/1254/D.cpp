#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
using namespace std;
using INT = long long;
using VI = vector<int>;
using pii = pair<int, int>;

const int mod = 998244353;
const int NN = 200011;
int n, q;
VI adj[NN];

int L[NN], R[NN];
int ind;
int son[NN];
const int MM = 611;
int big[NN];
int nb;
int flag[NN];
int B[NN];
int cnt[MM][NN];
int save[NN];
int tot;
int pa[NN];

int power(int a, int n, int mod, int ans=1) {
    for(; n; a=(INT)a*a%mod, n>>=1) if(n&1) ans = (INT) ans * a % mod;
    return ans;
}

inline void add(int &u, int v) {
    u += v;
    if(u >= mod) u -= mod;
}

inline void sub(int &u, int v) {
    u -= v;
    if(u < 0) u += mod;
}

void dfs(int u, int fa=0) {
    L[u] = ++ind;
    son[u] = 1;
    pa[u] = fa;
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dfs(v, u);

        son[u] += son[v];
    }
    R[u] = ind;
}

void rdfs(int u, int fa=0) {
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) {
            swap(adj[u][i], adj[u].back());
            adj[u].pop_back();
            i--;
            continue;
        }
        rdfs(v, u);
    }
}

inline void update(int u, int d) {
    while(u<=n) {
        add(B[u], d);
        u += u&-u;
    }
}

inline int calc(int u) {
    int ans = 0;
    while(u) {
        add(ans, B[u]);
        u -= u&-u;
    }
    return ans;
}

inline void del(int st, int ed, int d) {
    if(d < 0) d += mod;
    if(d == 0) return ;
    if(st > ed) return ;
  //  cerr<<st<<' '<<ed<<' '<<(INT)n * d % mod<<endl;
    update(st, d);
    update(ed+1, mod-d);
}


inline void up() {
    int u, d;

    scanf("%d %d", &u, &d);
    add(tot, d);
    if(flag[u]) {
        add(save[u], d);
        return ;
    }
//    cerr << d << endl;
    d = (INT)d * power(n, mod-2, mod) % mod;
//    cerr << (INT)d * n % mod << endl;
    int now =(INT)d * (n - son[u]) % mod;

    del(1, L[u]-1, now);
    del(R[u]+1, n, now);

    for(int v : adj[u]) {

        del(L[v], R[v], (INT)d * (son[v]) % mod);
    }
}

int rn;

inline void query() {
    int u;
    scanf("%d", &u);
    int ans = tot;

    sub(ans, calc(L[u]));

    for(int i=0; i<nb; i++) {
        int v = big[i];
        sub(ans, (INT)cnt[i][u] * save[v] % mod * rn % mod);
    }
    printf("%d\n", ans);
}

void pre(int u, int fa, int d, int i) {
    cnt[i][u] = d;
    for(int v : adj[u]) {
        if(v ^ fa) {
            pre(v, u, d, i);
        }
    }
}



int solve() {

    cin >> n >> q;
    rn = power(n, mod-2, mod);
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);


    for(int i=1; i<=n; i++) {
        if(adj[i].size() >= MM) {

            flag[i] = 1;
            cnt[nb][i] = 0;
            for(int v : adj[i]) {
                pre(v, i, v == pa[i] ? n - son[i] : son[v], nb);
            }
            big[nb++] = i;
        }
    }

    rdfs(1);
    for(int i=0; i<q; i++) {
        int  t;
        scanf("%d", &t);
        if(t==1) {
            up();
        }
        else {
            query();
        }
    }
}

int main() {
#ifdef redstar
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif // redstar
    solve();
}