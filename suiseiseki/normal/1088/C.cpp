#include <cstdio>
int a[2005];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",n+1);
	printf("2 %d 1\n",n);
	printf("1 %d 1000000\n",n);
	int x=999999;
	for(int i=1;i<n;i++){
		printf("2 %d %d\n",i,x);
		x--;
	}
	return 0;
}