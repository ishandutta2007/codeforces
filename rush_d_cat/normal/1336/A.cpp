#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,k,sz[N],dep[N];
vector<int> g[N];
void dfs(int u,int p){
	sz[u]=1; dep[u]=dep[p]+1;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dep[1]=-1; dfs(1,1);
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.push_back(dep[i]-(sz[i]-1));
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	long long ans=0;
	for(int i=0;i<k;i++)ans+=v[i];
	cout<<ans<<endl;
}