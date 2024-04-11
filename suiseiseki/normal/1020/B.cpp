#include <cstdio>
#include <cstring>
#define Maxn 1000
int a[Maxn+5];
bool vis[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1,j;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(j=i;!vis[j];j=a[j]){
			vis[j]=1;
		}
		printf("%d ",j);
	}
	puts("");
	return 0;
}