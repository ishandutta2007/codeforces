#include <cstdio>
#define Maxn 300000
#define Maxm 500000
struct Edge{
	int u,v;
	bool in;
}e[Maxm+5];
int n,m;
bool vis[Maxn+5];
int main(){
	int t;
	scanf("%d",&t);
	int num,ans;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=3*n;i++){
			vis[i]=0;
		}
		ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&e[i].u,&e[i].v);
			e[i].in=0;
			if(!vis[e[i].u]&&!vis[e[i].v]){
				vis[e[i].u]=1;
				vis[e[i].v]=1;
				e[i].in=1;
				ans++;
			}
		}
		if(ans>=n){
			puts("Matching");
			num=0;
			for(int i=1;i<=m;i++){
				if(e[i].in){
					printf("%d ",i);
					num++;
					if(num==n){
						break;
					}
				}
			}
			puts("");
		}
		else{
			puts("IndSet");
			num=0;
			for(int i=1;i<=3*n;i++){
				if(!vis[i]){
					printf("%d ",i);
					num++;
					if(num==n){
						break;
					}
				}
			}
			puts("");
		}
	}
	return 0;
}