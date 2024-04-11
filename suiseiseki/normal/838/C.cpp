#include <cstdio>
#include <cstring>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
int Mod=1000000009;
const int Maxn=250000;
const int Maxb=18;
const int Maxk=26;
int n,k;
int f[Maxk+5][Maxn+5];
int frac[Maxn+5],inv_f[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int A(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod;
}
int dfs(int x,int mask){
	if(f[x][mask]!=-1){
		return f[x][mask];
	}
	if(mask==0){
		f[x][mask]=frac[n];
		for(int i=1;i<=x;i++){
			f[x][mask]=1ll*f[x][mask]*(k-i+1)%Mod;
		}
		return f[x][mask];
	}
	f[x][mask]=0;
	int nmask=mask-(mask&(-mask));
	for(int i=nmask;i;i=(i-1)&nmask){
		f[x][mask]=(f[x][mask]+1ll*inv_f[mask-i]*dfs(x+1,i))%Mod;
	}
	f[x][mask]=(f[x][mask]+1ll*inv_f[mask]*dfs(x+1,0))%Mod;
	return f[x][mask];
}
int main(){
	scanf("%d%d%d",&n,&k,&Mod);
	init();
	if(n&1){
		printf("%d\n",quick_power(k,n,Mod));
		return 0;
	}
	memset(f,-1,sizeof f);
	int ans=quick_power(k,n,Mod);
	ans=(ans-dfs(0,n)+Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}