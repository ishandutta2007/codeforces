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

const int N=4e5+99,e=2e5+1;

int n,x,y,edge[N][2];
char ans[N];
set<pair<int,int> > g[N];
map<int,int> mark[N];

void dfs(int x,int dist){
	if(g[x].empty()) return ;
	pair<int,int> u=*g[x].begin(),p;
	p=u,p.F=x;
	g[u.F].erase(p);
	g[x].erase(u);
	ans[u.S]=(dist%2 ? 'r' : 'b');
	mark[u.F][x]=1;
	dfs(u.F,dist+1);
}
int main(){
	cin>>n;
	f(i,0,n){
		Gett(x,y);
		y+=e;
		edge[i][0]=x,edge[i][1]=y;
		g[x].insert(mp(y,i));
		g[y].insert(mp(x,i));
	}
	f(i,1,N)
		if(g[i].size()%2)
			dfs(i,0);
	f(i,1,N)
		if(g[i].size())
			dfs(i,0);
	f(i,0,n)
		if(ans[i]!='r' && ans[i]!='b')
			cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
	f(i,0,n)
		cout<<ans[i];
}