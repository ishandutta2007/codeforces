#include <queue>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=300000;
const int Mod=998244353;
int n,f[Maxn+5],ind[Maxn+5];
std::vector<int> g[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		ind[i]=k;
		for(int j=1,x;j<=k;j++){
			scanf("%d",&x);
			g[x].push_back(i);
		}
	}
	std::queue<int> q;
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(!ind[i]){
			q.push(i);
			f[i]=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cnt++;
		ans=std::max(ans,f[x]);
		for(int i=0;i<(int)g[x].size();i++){
			int y=g[x][i];
			if(y<x){
				f[y]=std::max(f[y],f[x]+1);
			}
			else{
				f[y]=std::max(f[y],f[x]);
			}
			if(!--ind[y]){
				q.push(y);
			}
		}
	}
	if(cnt!=n){
		puts("-1");
	}
	else{
		printf("%d\n",ans);
	}
	for(int i=1;i<=n;i++){
		ind[i]=f[i]=0;
		g[i].clear();
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}