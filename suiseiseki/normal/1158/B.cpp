#include <cstdio>
#define Maxn 10000
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		printf("%d",(i%((n-k)/2+1))>0);
	}
	return 0;
}
/////