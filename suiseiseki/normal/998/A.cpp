#include <cstdio>
#define Maxn 10
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	int tmp=0;
	a[0]=(1<<30);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[tmp]){
			tmp=i;
		}
	}
	if(n<2){
		puts("-1");
		return 0;
	}
	if(n==2&&a[1]==a[2]){
		puts("-1");
		return 0;
	}
	puts("1");
	printf("%d\n",tmp);
	return 0;
}