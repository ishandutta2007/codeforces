#include <cstdio>
#define Maxn 100
int n,x,a,b;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&x,&a,&b);
		if(a>b){
			a^=b^=a^=b;
		}
		printf("%d\n",mn(n-1,b-a+x));
	}
	return 0;
}