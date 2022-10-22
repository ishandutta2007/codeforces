#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define get(x,y) scanf("%I64d%I64d",&x,&y);
const int N=3e5+9;
ll n,m,deg[N],k,d[N],ans[N],s,mark[N],e=1e6,x,y,f;
map <ll,ll> mp;
vector<int> g[N];
void dfs(ll x,ll par,ll rt){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i],x,rt);
	}
	if(x!=rt && deg[x]%2!=d[x]){
		deg[par]++;
		ans[s]=mp[x*e+par],s++;
	}
}
int main(){
	cin>>n>>m;
	f(i,1,n+1){scanf("%I64d",&d[i]);
		f+=(d[i]%2==1);
		if(d[i]==-1) k=i;
	}
	f(i,1,m+1){
		get(x,y);
		g[y].pb(x);
		g[x].pb(y);
		mp[y*e+x]=i;mp[y+x*e]=i;
	}	
	if(k>0)
		dfs(k,0,k);
	if(k==0 && f%2==0)
		dfs(1,0,1);
	if(k==0 && f%2==1){
		cout<<-1;return 0;
	}
	cout<<s<<endl;
	f(i,0,s) cout<<ans[i]<<endl;
}