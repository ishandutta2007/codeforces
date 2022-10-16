#include <cstdio>
#define Maxn 1000
#define Mod 998244353
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
int main(){
	int w,h;
	scanf("%d%d",&w,&h);
	printf("%d\n",ksm(2,w+h));
	return 0;
}