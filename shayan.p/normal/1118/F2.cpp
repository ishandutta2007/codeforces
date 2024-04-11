// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,mod=998244353;

vector<int>v[maxn],col[maxn],g[maxn];
int nxt[maxn],par[maxn],cl[maxn],h[maxn];
int dp[2][maxn];

int Find(int u){
    return par[u]<0?u:par[u]=Find(par[u]);
}
void Merge(int a,int b){
    if((a=Find(a))==(b=Find(b))) return;
    if(par[a]>par[b]) swap(a,b);
    int nx=h[nxt[a]]<h[nxt[b]]?nxt[a]:nxt[b];
    par[a]+=par[b];
    par[b]=a;
    nxt[a]=nx;
    if(cl[a]!=0 && cl[b]!=0 && cl[a]!=cl[b]) cout<<0<<endl,exit(0);
    if(cl[a]==0) cl[a]=cl[b];
}
void dfs(int u,int par=0){
    nxt[u]=par;
    h[u]=h[par]+1;
    for(int y:v[u]){
	if(y!=par)
	    dfs(y,u);
    }
}
void dfs2(int u,int par=0){
    for(int y:g[u]){
	if(y!=par){
	    dfs2(y,u);
	    dp[0][y]=(dp[0][y]+dp[1][y])%mod;
	}
    }
    if(cl[u]==0){
	dp[0][u]=1;
	dp[1][u]=0;
	for(int y:g[u]){
	    if(y!=par){
		dp[1][u]=(1ll*dp[1][u]*dp[0][y]+1ll*dp[0][u]*dp[1][y])%mod;
		dp[0][u]=1ll*dp[0][u]*dp[0][y] %mod;
	    }
	}
    }
    else{
	dp[0][u]=0;
	dp[1][u]=1;
	for(int y:g[u]){
	    if(y!=par)
		dp[1][u]=1ll*dp[1][u]*dp[0][y] %mod;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
	cin>>cl[i];
	col[cl[i]].PB(i);
	par[i]=-1;
    }
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    for(int i=1;i<=k;i++){
	int u=col[i].back();
	col[i].pop_back();
	for(int y:col[i]){
	    int A=u,B=y;
	    while(Find(A)!=Find(B)){
		A=Find(A),B=Find(B);
		if(h[nxt[A]]<h[nxt[B]]) swap(A,B);
		Merge(A,nxt[A]);
	    }
	}
    }
    int rt=-1;
    for(int u=1;u<=n;u++){
	rt=Find(u);
	for(int y:v[u]){
	    if(Find(u)!=Find(y))
		g[Find(u)].PB(Find(y));
	}
    }
    dfs2(rt);
    int Ans=dp[1][rt];
    if(Ans<0) Ans+=mod;
    return cout<<Ans<<endl,0;
}