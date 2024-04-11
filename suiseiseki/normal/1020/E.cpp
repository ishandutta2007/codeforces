#include <cstdio>
#include <vector>
using namespace std;
#define Maxn 1000000
vector<int> edge[Maxn+5];
bool vis[Maxn+5];
bool choose[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=choose[i]=1;
			for(int j=0;j<(int)edge[i].size();j++){
				vis[edge[i][j]]=1;
			}
		}
	}
	for(int i=n;i>0;i--){
		if(choose[i]){
			for(int j=0;j<(int)edge[i].size();j++){
				choose[edge[i][j]]=0;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(choose[i]){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(choose[i]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}