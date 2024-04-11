#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(n%5)%3+1);
	return 0;
}