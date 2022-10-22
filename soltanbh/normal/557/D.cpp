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
#define F first
 
const int N=1e5+9;

int n,m,u,v,t,mx,e,d[2],vis[N],fa[N];
vector<int> g[N];
ll ans;

void dfs(int x,int dist){
	d[dist]++;
	fa[x]=dist;
	vis[x]=1,t++;
	f(i,0,g[x].size())
		if(vis[g[x][i]] && fa[g[x][i]]==fa[x]){
			cout<<0<<" "<<1;
			exit(0);
		}
	f(i,0,g[x].size())
		if(!vis[g[x][i]])
			dfs(g[x][i],1-dist);
}
int main(){
	cin>>n>>m;
	if(m==0) return cout<<3<<" "<<1ll*n*(n-1)*(n-2)/6,0;
	f(i,0,m){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1)
		if(!vis[i]){
			t=d[0]=d[1]=0;
			dfs(i,0);
			maxm(mx,t);
			if(t==2) e++;
			ans+=1ll*t*(t-1)/2-1ll*d[0]*d[1];
		}
	if(mx==2) return cout<<2<<" "<<1ll*e*(n-2),0;
	cout<<1<<" "<<ans;
}