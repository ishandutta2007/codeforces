#include <cstdio>
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",(6*n-1)*k);
	for(int i=1;i<=n;i++){
		printf("%d %d %d %d\n",(6*i-1)*k,(6*i-4)*k,(6*i-3)*k,(6*i-5)*k);
	}
	return 0;
}