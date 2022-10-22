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
#define add(x,y) x.F+=y.F,x.S+=y.S;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9;

int n,u,v,v1,v2,v3,x,s,w[N],d[N],vis[N],mark[N];
pair<int,int> ans,dp1[N],dp2[N];
vector<pair<int,int> > pairs,e;
vector<int> g[N];

void del_edge(int x,int y){
	f(i,0,g[x].size()) if(g[x][i]==y){ g[x].erase(g[x].begin()+i);break; }
	f(i,0,g[y].size()) if(g[y][i]==x){ g[y].erase(g[y].begin()+i); break; }
}
void dfs(int x,int par){
	pair<int,int> p,e;
	dp1[x].F=dp1[x].S=dp2[x].F=dp2[x].S=0;
	p.F=p.S=0;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			e=mp(dp2[g[x][i]].F-dp1[g[x][i]].F+1,dp2[g[x][i]].S-dp1[g[x][i]].S+(w[x]!=w[g[x][i]]));
			if(e>p)
				p=e,d[x]=g[x][i];
			add(dp2[x],dp1[g[x][i]]);
		}
	dp1[x]=dp2[x];
	add(dp1[x],p);
}
void dfs1(int x,int par){
	int io=0;
	vis[x]=1;
	f(i,0,g[x].size()){
		if((vis[g[x][i]] && (g[x][i]!=par || io==1)))
			v1=par,v2=x,v3=g[x][i];
		io+=(g[x][i]==par);
	}
	f(i,0,g[x].size())
		if(!vis[g[x][i]])
			dfs1(g[x][i],x);
}
void calc_pairs(int x,int par,int src){
	if(dp1[x]==dp2[x]) src=1;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			if(g[x][i]==d[x] && src==0){
				e.pb(mp(x,g[x][i]));
				calc_pairs(g[x][i],x,1);
			}
			else
				calc_pairs(g[x][i],x,0);
		}
}
void solve(int root){
	pair<int,int> res;
	res.F=res.S=0,v1=v2=v3=0;
	e.clear();
	dfs1(root,0);
	del_edge(v1,v2);
	dfs(root,0);
	calc_pairs(root,0,0);
	res=dp1[root];
	
	g[v1].pb(v2),g[v2].pb(v1);
	del_edge(v2,v3);
	dfs(root,0);
	if(dp1[root]>res){
		e.clear();
		res=dp1[root];
		calc_pairs(root,0,0);
	}
	f(i,0,e.size())
		pairs.pb(e[i]);
	add(ans,res);
}

int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>u>>w[i];
		g[i].pb(u);
		g[u].pb(i);
		w[i]--;
	}
	f(i,1,n+1)
		if(!vis[i])
			solve(i);
	cout<<ans.F<<" "<<ans.S<<endl;
	f(i,0,pairs.size())
		cout<<pairs[i].F<<" "<<pairs[i].S<<endl;
}