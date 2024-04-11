#include <cstdio>
const int Maxn=100000;
int n;
int a[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(!(n&1)){
		int ans=a[1];
		for(int i=1;i<=(n>>1)-1;i++){
			ans=(ans^a[i<<1]^a[i<<1|1]);
		}
		if(ans!=a[n]){
			puts("NO");
			return 0;
		}
		puts("YES");
		printf("%d\n",n-2);
		for(int i=1;i<=(n>>1)-1;i++){
			printf("1 %d %d\n",(i<<1),(i<<1|1));
		}
		for(int i=1;i<=(n>>1)-1;i++){
			printf("1 %d %d\n",(i<<1),(i<<1|1));
		}
		return 0;
	}
	puts("YES");
	printf("%d\n",((n>>1)<<1)-1);
	for(int i=1;i<=(n>>1);i++){
		printf("1 %d %d\n",(i<<1),(i<<1|1));
	}
	for(int i=(n>>1)-1;i>0;i--){
		printf("1 %d %d\n",(i<<1),(i<<1|1));
	}
	return 0;
}