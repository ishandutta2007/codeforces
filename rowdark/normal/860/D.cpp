#include<vector>
#include<stdio.h>
using namespace std;
int belong[200100];
int f[200100];
int cnt[200100];
bool vis[200100];
vector<int> V[200100];
vector<int> NV[200100];
int n,m;
void dfs(int x){
	cnt[x]=0;
	vis[x]=1;
	for(auto &&y:V[x]){
		int z=f[y]^x;
		if(!vis[z]){
			belong[y]=x;
			cnt[x]^=1;
		}
	}
	for(auto &&y:V[x]){
		int z=f[y]^x;
		if(!vis[z]){
			dfs(z);
			if(cnt[z]==1){
				belong[y]=z;
				cnt[z]^=1;
				cnt[x]^=1;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		f[i]=x^y;
		V[x].push_back(i);
		V[y].push_back(i);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]) dfs(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(auto &&y:V[i]){
			if(belong[y]==i){
				NV[i].push_back(f[y]^i);
			}
		}
		ans+=NV[i].size()/2;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		for(int j=0;j+1<int(NV[i].size());j+=2){
			printf("%d %d %d\n",NV[i][j],i,NV[i][j+1]);
		}
	}
	return 0;
}