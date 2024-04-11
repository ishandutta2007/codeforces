#include <cstdio>
const int Maxn=2000;
int n;
int dep[Maxn+5][Maxn+5];
bool g[Maxn+5][Maxn+5];
int num[Maxn+5];
bool vis[Maxn+5];
void query(int x,int *d){
	printf("? %d\n",x);
	fflush(stdout);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
}
int main(){
	scanf("%d",&n);
	query(1,dep[1]);
	for(int i=2;i<=n;i++){
		num[dep[1][i]]++;
	}
	int sum_1=0,sum_2=0;
	for(int i=1;i<=n;i+=2){
		sum_1+=num[i];
	}
	for(int i=2;i<=n;i+=2){
		sum_2+=num[i];
	}
	vis[1]=1;
	if(sum_1<sum_2){
		for(int i=2;i<=n;i++){
			if(dep[1][i]&1){
				query(i,dep[i]);
				vis[i]=1;
			}
		}
	}
	else{
		for(int i=2;i<=n;i++){
			if(!(dep[1][i]&1)){
				query(i,dep[i]);
				vis[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			for(int j=1;j<=n;j++){
				if(dep[i][j]==1){
					g[i][j]=g[j][i]=1;
				}
			}
		}
	}
	printf("!\n");
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]){
				printf("%d %d\n",i,j);
			}
		}
	}
	fflush(stdout);
	return 0;
}