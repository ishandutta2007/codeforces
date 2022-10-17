#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=a;b++){
			if(a%b!=0){
				continue;
			}
			if(a*b<=n){
				continue;
			}
			if(a/b>=n){
				continue;
			}
			printf("%d %d\n",a,b);
			return 0;
		}
	}
	puts("-1");
	return 0;
}