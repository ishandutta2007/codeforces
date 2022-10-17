#include <cstdio>
int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		printf("%d\n",(n>>1));
	}
	return 0;
}