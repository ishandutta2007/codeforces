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

const int N=1e6+99;

int n,t,l[N],r[N];
ll dp[N],pd[N];
vector<int> g[N];

void dfs(int x,int par){
    dp[x]=pd[x]=0;
    f(i,0,g[x].size()){
        if(g[x][i]!=par){
            dfs(g[x][i],x);
            dp[x]+=max(dp[g[x][i]]+abs(l[x]-l[g[x][i]]),pd[g[x][i]]+abs(l[x]-r[g[x][i]]));
            pd[x]+=max(dp[g[x][i]]+abs(r[x]-l[g[x][i]]),pd[g[x][i]]+abs(r[x]-r[g[x][i]]));
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        f(i,1,n+1) g[i].clear();
        f(i,1,n+1) Gett(l[i],r[i]);
        f(i,1,n){
            int u,v;
            Gett(u,v);
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1,0);
        cout<<max(dp[1],pd[1])<<endl;
    }
}