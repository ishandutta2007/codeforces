//D
#include <bits/stdc++.h>
using namespace std;

#define N 1011
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))

typedef long long ll;

struct dat{
    ll r, x, y;
    dat(ll r = 0, ll x = 0, ll y = 0) : r(r), x(x), y(y){}
}p[N];

bool cmp(dat a, dat b){
    return a.r > b.r;
}

vector <int> con[N];
int n, m, qq;
ll kx[N], ky[N], col[N];
int dp[N], fa[N];
bool link[N][N];
bool vis[N];
int rmq[N][13];

void dfs(int u){
    for(int j = 0; j < con[u].size(); j ++){
        int v = con[u][j];
        if(vis[v]) continue;
        vis[v] = 1;
        dp[v] = dp[u] + 1;
        fa[v] = u;
        dfs(v);
    }
}

void RMQ(){
    for(int i = 0; i <= m; i ++) rmq[i][0] = i, rmq[i][1] = fa[i];
    for(int len = 2; len < 12; len ++){
        for(int i = 0; i <= m; i ++){
            int j = fa[rmq[i][len - 1]];
            rmq[i][len] = rmq[j][len - 1];
        }
    }
}

int lca(int a, int b){
    int r = 11;
    while(r > -1){
        int c = rmq[a][r];
        if(link[c][b]) r --;
        else a = fa[c];
    }
    return a;
}

int main() {
    ///freopen ("d.in", "r", stdin);
    scanf ("%d %d %d", &n, &m, &qq);
    for(int i = 0; i < n; i ++) scanf("%I64d %I64d", &kx[i], &ky[i]);
    for(int i = 1; i <= m; i ++) scanf("%I64d %I64d %I64d", &p[i].r, &p[i].x, &p[i].y);
    sort(p + 1, p + m + 1, cmp);

    for(int i = 1; i <= m; i ++){
        for(int j = i + 1; j <= m; j ++) {
            ll rr = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            if(rr > p[i].r * p[i].r) continue;
            con[i].push_back(j);
            link[i][j] = 1;
            fa[j] = i;
        }
    }

    for(int i = 1; i <= m; i ++) {
        link[0][i] = 1;
        if(!fa[i]) con[0].push_back(i), link[0][i] = 1;
    }
    for(int i = 0; i <= m; i ++) link[i][i] = 1;

    vis[0] = 1;
    dfs(0);
    RMQ();

    p[0].r = 10000000000000ll;
    for(int i = 0; i < n; i ++) {
        for(int j = m; j >= 1; j --){
            ll rr = (p[j].x - kx[i]) * (p[j].x - kx[i]) + (p[j].y - ky[i]) * (p[j].y - ky[i]);
            if(rr < p[j].r * p[j].r) {col[i] = j; break;}
        }
    }

    for(int i = 0; i < qq; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a --, b --;
        a = col[a], b = col[b];
        int c = lca(a, b);
        printf("%d\n", dp[a] - dp[c] + dp[b] - dp[c]);
    }
    ///return 9;
}