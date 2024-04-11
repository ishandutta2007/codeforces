#include <cstdio>
#define Mod 1000000007
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
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",ksm(ksm(2,m)-1,n));
	return 0;
}