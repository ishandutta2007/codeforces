#include <cstdio>
const int Maxn=1000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",n*3);
	for(int i=1;i<=n;i+=2){
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
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