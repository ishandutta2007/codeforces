#include <cstdio>
int main(){
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(n%m==0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}