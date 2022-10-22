#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);

const int N=8e5+9;

ll n,m,x,y,dp[N],mark[N],e=1e6,q,edge[N][2],mark1[N],mark2[N],cnt=0,mx,amx,mark3[N];
vector<int> g[N],g1[N],v;
map<ll,ll> brshi,yal;
void dfs(ll x,ll par){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==1 && g[x][i]!=par)
			dp[x]++,dp[g[x][i]]--;
	}
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i],x),dp[x]+=dp[g[x][i]];
	}
	if(dp[x]==0 && x!=1)
		brshi[x*e+par]=1,brshi[par*e+x]=1;
}
void dfs1(ll x,ll par){
	mark1[x]=1,cnt++;
	f(i,0,g1[x].size()){
		if(g1[x][i]!=par && mark1[g1[x][i]]==1)
			yal[x*e+g1[x][i]]=1;
	}
	f(i,0,g1[x].size()){
		if(mark1[g1[x][i]]==0){
			yal[x*e+g1[x][i]]=1;
			dfs1(g1[x][i],x);
		}
	}
}
void dfs3(ll x){
	mark3[x]=1;
	f(i,0,g[x].size()){
		if(mark3[g[x][i]]==0){
			yal[x*e+g[x][i]]=0,yal[g[x][i]*e+x]=1;
			dfs3(g[x][i]);
		}
	}
}
void dfs2(ll x){
	mark2[x]=1,mark3[x]=1;
	v.pb(x);
	f(i,0,g1[x].size()){
		if(mark2[g1[x][i]]==0)
			dfs2(g1[x][i]);
	}
	
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Get(x,y);
		edge[i][0]=x,edge[i][1]=y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	f(i,1,n+1){
		f(j,0,g[i].size()){
			if(!brshi[i*e+g[i][j]])
				g1[i].pb(g[i][j]);
		}
	}
	f(i,1,n+1){
		cnt=0;
		if(mark1[i]==0)
			dfs1(i,0);
		if(cnt>mx)
			mx=cnt,amx=i;
	}
	dfs2(amx);
	f(i,0,v.size())
		dfs3(v[i]);
	cout<<mx<<endl;
	f(i,0,m){
		if(yal[edge[i][0]*e+edge[i][1]]==1)	
			cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
		else
			cout<<edge[i][1]<<" "<<edge[i][0]<<endl;
	}
}