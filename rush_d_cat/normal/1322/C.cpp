#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500000+10;
int t,n,m;
LL c[N];
int u[N],v[N];
vector<int> g[N];
map< vector<int>, LL> mp;
LL gcd(LL x, LL y) {
	return y==0?x:gcd(y,x%y);
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=m;i++){
			int u,v; scanf("%d%d",&u,&v);
			g[v].push_back(u);
		}
		mp.clear();
		for(int i=1;i<=n;i++){
			sort(g[i].begin(),g[i].end());
			if(g[i].size())mp[g[i]]+=c[i];
		}
		LL ans=0;
		for(auto p: mp){
			ans=gcd(ans,p.second);
		}
		printf("%lld\n", ans);
	}
}