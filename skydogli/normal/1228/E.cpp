#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define Mod 1000000007
#define MN 255
LL ksm(LL a,LL x){
	LL w=a,ans=1;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,k,C[MN][MN],pk[MN],p[MN],f[MN][MN];
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;++i)C[i][i]=C[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			C[j][i]=(C[j-1][i-1]+C[j-1][i])%Mod;
	pk[0]=p[0]=1;
	for(int i=1;i<=n;++i){
		pk[i]=pk[i-1]*k%Mod;
		p[i]=p[i-1]*(k-1)%Mod;
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int l=0;l<=j;++l){
				int tmp=0;
				if(l==j)tmp=p[l];
				(f[i][j]+=(f[i-1][l]*C[n-l][j-l]%Mod*((pk[l]+Mod-tmp)%Mod)%Mod*p[n-j]%Mod))%=Mod;
			}
	printf("%I64d",f[n][n]);
	return 0;
}