#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const int N = 200000 + 10;
int t,n,sz[N],m;
vector<int> g[N];
void dfs(int u,int p){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int p[N]; LL e[N];
bool cmp1(int x,int y){
	return x>y;
}
bool cmp2(LL x,LL y){
	return x>y;
}
int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v; scanf("%d%d",&u,&v);
			g[u].push_back(v); g[v].push_back(u);
		}
		dfs(1,1);
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n-1;i++){
			e[i]=1LL*sz[i+1]*(n-sz[i+1]);
		}
		sort(p+1,p+1+m,cmp1);
		sort(e+1,e+1+n-1,cmp2);
		if(n-1>m) {
			LL ans=0;
			for(int i=m+1;i<=n-1;i++) p[i]=1;
			for(int i=1;i<=n-1;i++)(ans+=(e[i]%MOD*p[i]%MOD))%=MOD;
			printf("%lld\n", ans);
		} else {
			LL ans=0;
			int pre=m-(n-1)+1;
			LL M=1;
			// m: [1,pre] [pre+1,.....m]
			// n-1      1 [2,.....n-1]
			for(int i=1;i<=pre;i++){
				M=M*(p[i]%MOD)%MOD;
			}
			//printf("# %lld\n", m);
			M=M*e[1]%MOD;
			ans=M;
			for(int i=2;i<=n-1;i++){
				(ans+=e[i]*(p[pre+i-1]%MOD)%MOD)%=MOD;
			}
			printf("%lld\n", ans);
		}
	}
}