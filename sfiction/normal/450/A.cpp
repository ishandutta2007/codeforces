/*
ID: Sfiction
OJ: CF
PROB: 450A
*/
#include <cstdio>

int main(){
	int n,m;

	scanf("%d%d",&n,&m);

	int max=0,num,x;
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		x=(x-1)/m+1;
		if (max<=x){
			max=x;
			num=i;
		}
	}
	printf("%d",num);
	return 0;
}