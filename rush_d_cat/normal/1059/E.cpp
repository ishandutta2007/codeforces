#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n,L; LL S;
vector<int> g[N];
int dep[N],par[N][20],sum[N][20],w[N],p[N];
int top[N],cnt[N];
struct Nod {
    int x;
    bool operator < (const Nod & o) const {
        return top[x] > top[o.x];
    }
};

void dfs(int u,int p) {
    dep[u] = dep[p]+1;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i]; if(p==v) continue;
        par[v][0]=u, sum[v][0]=w[v];
        dfs(v, u);
    }
}

LL getdis(int u,int d) {
    LL ans=0;
    for(int i=19;i>=0;i--) {
        if(d>>i&1) {
            ans = ans + sum[u][i];
            u = par[u][i];
        }
    }
    return ans;
}

void init() {
    par[1][0]=1,sum[1][0]=w[1];
    dfs(1,1);
    for(int j=1;j<20;j++)
    for(int i=1;i<=n;i++) {
        par[i][j] = par[par[i][j-1]][j-1];
        sum[i][j] = sum[i][j-1] + sum[par[i][j-1]][j-1];
    }
    //printf("%d\n", par[3][1]);
    for(int i=1;i<=n;i++) {
        int l=0,r=min(dep[i],L)+1; //printf("i=%d, r=%d\n", i,r);
        while(r-l>1) {
            int mid=(l+r)>>1;
            if(getdis(i, mid)<=S) {
                l = mid;
            } else {
                r = mid;
            }
        }
        top[i] = dep[i] - l + 1;
        //printf("top[%d]=%d, r=%d\n", i,top[i],r);
    }
}
int mn[N],dp[N];
void solve(int u,int p) {
    mn[u] = N;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i]; if(p==v) continue;
        solve(v, u);
        mn[u] = min(mn[u], mn[v]);
        dp[u] += dp[v];
    }
    if (mn[u] > dep[u]) {
        dp[u] = dp[u]+1; mn[u] = top[u];
    }
    //printf("dp[%d]=%d, mn=%d\n", u, dp[u], mn[u]);
}
int main() {
    scanf("%d%d%lld",&n,&L,&S);
    for(int i=1;i<=n;i++) {
        scanf("%d",&w[i]); 
        if (w[i] > S) return !printf("-1\n");
    }
    for(int i=2;i<=n;i++) {
        scanf("%d",&p[i]); 
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }
    init();
    solve(1,1);
    cout << dp[1] << endl;
}