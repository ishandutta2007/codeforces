#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ans1,ans2;
LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
void chk(LL x,LL bin){
	LL p=x/bin;
	for(LL j=1;j*j<=p;++j){
		if(p%j==0&&gcd(j,p/j)==1){if(ans2>p/j*bin) ans1=j*bin,ans2=p/j*bin;}
	}
}
int main(){
	LL x;
	ans2=1e18;
	scanf("%lld",&x);
	for(LL i=1;i*i<=x;++i){
		if(x%i==0){chk(x,i);}
	}
	printf("%lld %lld",ans1,ans2);
	return 0;
}