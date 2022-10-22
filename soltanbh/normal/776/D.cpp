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
 
const int N=2e5+9;

int t,n,m,k,x,r[N],col[N],mark[N];
vector<int> edge[N];
vector<pair<int,int> > g[N];

void dfs(int x,int c){
	col[x]=c;
	mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i].F])
			dfs(g[x][i].F,1-((c+g[x][i].S)%2));
}

int main(){
	cin>>n>>m;
	f(i,1,n+1) cin>>r[i];
	f(i,1,m+1){
		cin>>k;
		f(j,0,k){
			cin>>x;
			edge[x].pb(i);
		}
	}
	f(i,1,n+1){
		int u=edge[i][0],v=edge[i][1];
		g[u].pb(mp(v,r[i]));
		g[v].pb(mp(u,r[i]));
	}
	f(i,1,m+1)
		if(!mark[i])
			dfs(i,1);
	f(i,1,n+1)
		if((col[edge[i][0]]+col[edge[i][1]]+r[i])%2==0)
		 return cout<<"NO",0;
	cout<<"YES";
}