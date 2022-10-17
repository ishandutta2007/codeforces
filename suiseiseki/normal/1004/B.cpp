#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("%d",i&1);
	}
	puts("");
	return 0;
}