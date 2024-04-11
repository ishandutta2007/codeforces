#include <cstdio>
#define Maxn 1000
#define Mod 1000003
int x[Maxn+5];
int main() {
	int a;
	x[0]=1;
	x[1]=1;
	x[2]=3;
	for(int i=3;i<Maxn+5;i++){
		x[i]=x[i-1]*3%Mod;
	}
	while(scanf("%d",&a)!=EOF){
		printf("%d\n",x[a]);
	}
	return 0;
}