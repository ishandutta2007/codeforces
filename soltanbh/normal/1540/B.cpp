#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=205,mod=1e9+7,inv2=5e8+4;

int n,x,t,h1,h2,ans,a[N],Pow[N],mark[N],C[N][N],P[N][N];
vector<int> g[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void dfs2(int u,int par=0){
    if(mark[u]) h1--;
    else h2++;
    if(u<x){
        //cout<<x<<" "<<u<<" "<<h1<<" "<<h2<<endl;
        if(h1 && h2)
            Add(ans,P[h1][h2]);
        if(h1==0 && h2)
            Add(ans,1);
    }
    f(i,0,g[u].size())
        if(g[u][i]!=par)
            dfs2(g[u][i],u);
    if(mark[u]) h1++;
    else h2--;
}
void dfs1(int u,int rt){
    mark[u]=1;
    h1++;
    x=u;
    dfs2(rt);
    f(i,0,g[u].size())
        if(!mark[g[u][i]])
            dfs1(g[u][i],rt);
    h1--;
    mark[u]=0;
}
void solve(int u){
    dfs1(u,u);
    //exit(0);
}

int main(){
    Pow[0]=1;
    f(i,1,N)
        Pow[i]=1ll*Pow[i-1]*inv2%mod;
    f(i,0,N){
        C[0][i]=1;
        f(j,1,i+1)
            C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
    }
   cin>>n;
   f(i,1,n){
       int u,v;
       cin>>u>>v;
       g[u].pb(v);
       g[v].pb(u);
   }
   f(i,1,n+1)
       f(j,1,n+1)
           f(k,0,j)
               Add(P[i][j],1ll*C[i-1][i-1+k]*Pow[i+k]%mod);
   f(i,1,n+1)
       solve(i);
   //cout<<ans<<endl;
   ans=1ll*ans*pow(n,mod-2,mod)%mod;
   cout<<ans;
}