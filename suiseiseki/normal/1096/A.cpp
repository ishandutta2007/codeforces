#include <cstdio>
int main(){
	int t;
	scanf("%d",&t);
	int l,r;
	while(t--){
		scanf("%d%d",&l,&r);
		printf("%d %d\n",l,l<<1);
	}
	return 0;
}