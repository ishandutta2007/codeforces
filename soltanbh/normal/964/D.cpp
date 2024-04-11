#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,x,rt,mark[N],deg[N],dist[N],par[N];
set<pair<int,int> > s;
vector<int> ans,g[N];

void update(int x){
	deg[x]--;
	if(deg[x]%2) s.erase(mp(dist[x],x));
	else s.insert(mp(dist[x],x));
}
void dfs(int x,int dis){
	dist[x]=dis;
	deg[x]=(g[x].size()+(x!=rt));
	if(deg[x]%2==0)
		s.insert(mp(dis,x)),deg[x]=(g[x].size()+(x!=rt));

	f(i,0,g[x].size())
		dfs(g[x][i],dis+1);
}
void dfs_del(int x){
	ans.pb(x);
	mark[x]=1;
	
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs_del(g[x][i]);
}

int main(){
	cin>>n;
	
	if(!(n%2)) return cout<<"NO",0;
	cout<<"YES"<<endl;
	
	f(i,1,n+1){
		gett(x);
		if(x==0) rt=i;
		else
			g[x].pb(i),par[i]=x;
	}
	dfs(rt,0);
	while(s.size()){
		int u=(*s.rbegin()).S;
		s.erase(mp(dist[u],u));
		
		dfs_del(u);
		if(u!=rt)
			update(par[u]);
	}
	
	print(ans,ans.size());
}