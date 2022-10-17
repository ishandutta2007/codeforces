#include <cstdio>
#define Maxn 200000
int a[Maxn+5];
int n;
bool vis[Maxn+5];
int b[Maxn+5];
int col[Maxn+5];
int main(){
	int t;
	scanf("%d",&t);
	int len;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
			col[i]=0;
		}
		len=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				continue;
			}
			len++;
			for(int j=i;!vis[j];j=a[j]){
				b[j]=len;
				col[len]++;
				vis[j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",col[b[i]]);
		}
		puts("");
	}
	return 0;
}