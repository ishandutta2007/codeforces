#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MN 250005
int Mod;
int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,k;
int fac[MN],dfac[MN],inv[MN],f[19][MN];
int solve(int use,int S){
	if(f[use][S]!=-1)return f[use][S];
	int ret=0;
	if(!S){
		int ret=fac[n];
		for(int i=1;i<=use;++i)
			ret=1LL*ret*(k-i+1)%Mod;
//		cerr<<"!S "<<use<<" "<<S<<": "<<ret<<endl;
		return f[use][S]=ret;
	}
	if(use>k)return 0;
	int lbit=S&(-S);
	int U=S-lbit;
	for(int T=U;;T=(T-1)&U){
//		cerr<<"? "<<S<<" "<<T<<" "<<lbit<<endl;
		ret=(1LL*dfac[S-T]*solve(use+1,T)+ret)%Mod;	
		if(!T)break;
	}
//	cerr<<use<<" "<<S<<": "<<ret<<endl;
	return f[use][S]=ret;
}
int main(){
	scanf("%d%d%d",&n,&k,&Mod);
	if(n&1){printf("%d\n",ksm(k,n));return 0;}	
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	for(int i=2;i<=n;++i){
		fac[i]=1ll*fac[i-1]*i%Mod;
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=1ll*dfac[i-1]*inv[i]%Mod;
	}
	for(int i=0;i<=18;++i)
		for(int j=0;j<=n;++j)
			f[i][j]=-1;
	printf("%d\n",(ksm(k,n)-solve(0,n)+Mod)%Mod);
	return 0;
}