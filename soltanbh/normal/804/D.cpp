#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second

const int N=1e5+99;

int n,m,q,u,v,c,F[N],dp[N],sz[N],fa[N],dia[N],cmp[N],mark[N],sum[N];
vector<int> g[N],v1[N],v2[N];
map<int,pair<int,int> > res[N];
map<int,int> clc[N];
ll ans,ans1,ans2;

void dfs1(int x,int cp){
	cmp[x]=cp,sz[cp]++;
	mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]]){
			dfs1(g[x][i],cp);
			dp[x]=maxm(dp[x],dp[g[x][i]]+1);
		}
}
void dfs2(int x){
	mark[x]=0;
	int mx=fa[x]+1;
	f_(i,g[x].size()-1,0)
		if(mark[g[x][i]])
			F[g[x][i]]=mx,maxm(mx,dp[g[x][i]]+2);
	mx=0;
	f(i,0,g[x].size())
		if(mark[g[x][i]]){
			fa[g[x][i]]=max(mx,F[g[x][i]]);
			dfs2(g[x][i]);
			maxm(mx,dp[g[x][i]]+2);
		}
}
void calc(){
	ans1=0,ans2=0;
	int o;
	if(clc[u][v]){ ans1=res[u][v].first,ans2=res[u][v].S; return ;}
	f(i,0,min(dia[u]+1,dia[v])){
		o=v1[u][i];
		if(i) o-=v1[u][i-1];
		ans1+=1ll*o*v1[v][dia[v]-i-1];
		ans2+=1ll*o*v2[v][dia[v]-i-1]+1ll*i*o*v1[v][dia[v]-i-1];
	}
	ans2+=ans1;
	res[u][v]=mp(ans1,ans2);
}

int main(){
	cin>>n>>m>>q;
	f(i,0,m){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1)
		if(!mark[i])
			dfs1(i,++c);
	f(i,1,n+1)
		if(mark[i]==1)
			dfs2(i);
	f(i,1,n+1){
		maxm(fa[i],dp[i]);
		maxm(dia[cmp[i]],fa[i]);
	}
	f(i,1,c+1)
		f(j,0,dia[i]+1)
			v1[i].pb(0);
	f(i,1,n+1)
		v1[cmp[i]][fa[i]]++;
	f(i,1,c+1){
		v2[i].pb(0);
		f(j,1,v1[i].size())
			v2[i].pb(v2[i][j-1]+v1[i][j]*j),v1[i][j]+=v1[i][j-1];
	}
	f(i,0,q){
		Gett(u,v);
		u=cmp[u],v=cmp[v];
		if(dia[u]>dia[v]) swap(u,v);
		if(u!=v){
			calc();
			ans=1ll*sz[u]*v2[v][dia[v]]+1ll*sz[v]*v2[u][dia[u]]+1ll*sz[u]*sz[v];
			ans=ans-ans2+ans1*dia[v];
			printf("%.10lf\n",double(double(ans)/double(1ll*sz[u]*sz[v])));
		}
		else cout<<-1<<endl;
	}
}