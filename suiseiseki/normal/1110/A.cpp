#include <cstdio>
#define Maxn 100000
int a[Maxn+5];
int main(){
	int b,k;
	scanf("%d%d",&b,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	if(!(b&1)){
		if(a[k]&1){
			puts("odd");
		}
		else{
			puts("even");
		}
	}
	else{
		for(int i=1;i<=k;i++){
			ans+=a[i];
			ans&=1;
		}
		if(ans){
			puts("odd");
		}
		else{
			puts("even");
		}
	}
	return 0;
}