#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
const int Maxn=1000;
int a[Maxn+5];
int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	int sum;
	while(t--){
		sum=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",mn(sum,m));
	}
	return 0;
}