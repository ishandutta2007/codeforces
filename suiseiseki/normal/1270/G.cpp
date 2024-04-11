#include <cstdio>
const int Maxn=1000000;
int n,m;
bool vis[Maxn+5];
int a[Maxn+5],c[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		m=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]=i-a[i];
		}
		int i;
		for(i=1;!vis[i];vis[i]=1,i=a[i]);
		for(int j=i;c[++m]=j,a[j]!=i;j=a[j]);
		printf("%d\n",m);
		for(i=1;i<=m;i++){
			printf("%d ",c[i]);
		}
		puts("");
	}
	return 0;
}