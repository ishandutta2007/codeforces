#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 100005
const int inf =1e18;
int n,a[MN],b[MN],fa[MN],k[MN];
vector<int>edge[MN];
int f[MN];
void dfs(int x){
	f[x]=a[x];
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		dfs(v);
		if(f[v]<0)f[x]+=max(1.0*f[v]*k[v],-1e18);
		else f[x]+=f[v];
		f[x]=max(f[x],-inf);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]=b[i]-a[i];
	}
	for(int i=2;i<=n;++i){
		cin>>fa[i]>>k[i];
		edge[fa[i]].push_back(i);
	}
	dfs(1);
	puts(f[1]>=0?"YES":"NO");
	return 0;
}