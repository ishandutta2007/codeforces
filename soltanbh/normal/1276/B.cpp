#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b)for(ll i=a;i>=b;i--)
#define	ll long long
#define pb push_back
using namespace	std;
ll t,l,q,n,m,a,b,mark[200009],ans1,ans2,x,y;
vector<int> g[200009];
int dfs(int x,int y){
	if(x==y){l=0;return 0;}
	mark[x]=1;
	t++;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i],y);
	}
}
int main(){
	cin>>q;
	f(salam,0,q){
		f(i,1,n+1) g[i].clear(),mark[i]=0;ans1=0,ans2=0;
		cin>>n>>m>>a>>b;
		f(i,0,m){cin>>x>>y;g[x].pb(y),g[y].pb(x);}
		f(i,0,g[a].size()){
			if(mark[g[a][i]]==0){
				l=1,t=0;mark[a]=1;
				dfs(g[a][i],b);
				ans1+=l*t;}}
		f(i,0,g[b].size()){
			if(mark[g[b][i]]==0){
				mark[a]=0,l=1,t=0;mark[b]=1;
				dfs(g[b][i],a);
				ans2+=l*t;}
		}
		cout<<ans1*ans2<<endl;
	}
}