#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1e6+5,inf=1e9+7;
int n;
vi g[N];
pr dp[2][N];
vi opt[N];
pr operator+(const pr&x,const pr&y){return mp(x.st+y.st,x.nd+y.nd);}
void dfs(int x,int fa){
    dp[0][x]=mp(0,1);
    dp[1][x]=mp(-1,0);
    for(int v:g[x])if(v!=fa){
        dfs(v,x);
        dp[1][x]=dp[1][x]+dp[0][v]+mp(0,1);
        pr v0=dp[0][x]+dp[0][v],v1=dp[0][x]+dp[1][v]+mp(0,1);
        if(v0<v1)dp[0][x]=v0,opt[x].pb(0);else dp[0][x]=v1,opt[x].pb(1);
    }
}
int cnt[N],typ[N];
void col(int x,int fa,int ty){
    typ[x]=ty;
    if(ty==0){
        cnt[x]=1;
    }else{
        cnt[x]=(fa!=0&&typ[fa]==0);
    }
    int pt=0;
    for(int v:g[x])if(v!=fa){
        if(ty==0){
            col(v,x,opt[x][pt]);
        }else{
            col(v,x,0);
            ++cnt[x];
        }
        ++pt;
    }
}
int main(){
    scanf("%d",&n);
    rep(i,n-1){
        int x,y;scanf("%d%d",&x,&y);
        g[x].pb(y),g[y].pb(x);
    }
    if(n==2){
        printf("2 2\n1 1\n");
        return 0;
    }
    dfs(1,0);
    if(dp[0][1]<dp[1][1]){
        printf("%d %d\n",-dp[0][1].st,dp[0][1].nd);
        col(1,0,0);
    }else{
        printf("%d %d\n",-dp[1][1].st,dp[1][1].nd);
        col(1,0,1);
    }
    rep(i,n)printf("%d%c",cnt[i]," \n"[i==n]);
    return 0;
}
/*


*/