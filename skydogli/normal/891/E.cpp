#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
#define MN 5005
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,k,a[MN],f[MN];
signed main(){
	scanf("%lld%lld",&n,&k);
	f[0]=1;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		for(int j=i;j;--j){
			f[j]=(f[j]*a[i]-f[j-1]+Mod)%Mod;
		}
		f[0]=f[0]*a[i]%Mod;
	}
	int res=0,tmp=1,inv=ksm(n,Mod-2);
	for(int i=0;i<=n;++i){
		res=(res+f[i]*tmp)%Mod;
		tmp=tmp*(k-i)%Mod*inv%Mod;
	}
	printf("%lld\n",(f[0]-res+Mod)%Mod);
	return 0;
}