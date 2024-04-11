#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
#define MN 2005
int n,k,a[MN],inv[MN],ans[MN];
signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	inv[1]=1;for(int i=2;i<=n;++i)inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=1;i<=n;++i){
		int tmp=1;
		for(int j=i;j<=n;++j){
			if(j>i)tmp=tmp*(k+j-i-1)%Mod*inv[j-i]%Mod;
			ans[j]=(ans[j]+tmp*a[i])%Mod;
		}
	}
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}