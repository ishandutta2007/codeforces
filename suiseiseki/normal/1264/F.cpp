#include <cstdio>
const int w=445049;
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	n=1500000;
	printf("%lld %lld\n",1ll*a*n*w+1,1ll*b*n*w);
	return 0;
}