#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
#define pow ksm
#define lld I64d
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
#define MN 1000005
int n,k,pre[MN],fac[MN],suf[MN],ans,y[MN];
signed  main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k+3;++i)y[i]=(y[i-1]+ksm(i,k))%Mod;
	if(n<=k+3){printf("%lld",y[n]);return 0;}
	pre[0]=fac[0]=1;suf[k+3]=1;
	for(int i=k+2;i;--i)suf[i]=suf[i+1]*(n-i)%Mod;
	
	for(int i=1;i<=k+2;++i){
		pre[i]=pre[i-1]*(n-i)%Mod;
		fac[i]=fac[i-1]*ksm(i,Mod-2)%Mod;
	}
	for(int i=1;i<=k+2;++i){
		ans=(ans+y[i]*(pre[i-1]*suf[i+1]%Mod)%Mod*fac[k+2-i]%Mod*fac[i-1]%Mod*(((k+2-i)&1)?-1:1)+Mod)%Mod;
	}
	printf("%lld",ans);
	return 0;
}