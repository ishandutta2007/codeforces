#include <cstdio>
#include <cmath>
int main(){
	int n;
	scanf("%d",&n);
	int x=(int)sqrt(n*1.0);
	printf("%d\n",(n+x-1)/x+x);
	return 0;
}