#include <cstdio>
const int Maxk=200;
const int Mod=1000000007;
int n,k;
int S[Maxk<<1|5][Maxk<<1|5];
int inv[Maxk<<1|5];
void init(){
	inv[1]=1;
	for(int i=2;i<=(Maxk<<1);i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	S[0][0]=1;
	for(int i=1;i<=(Maxk<<1);i++){
		for(int j=(Maxk<<1);j>=0;j--){
			S[i][j]=(1ll*S[i-1][j]*j+(j==0?0:S[i-1][j-1]))%Mod;
		}
	}
}
int C(int n,int m){
	if(m==0){
		return 1;
	}
	return 1ll*C(n-1,m-1)*n%Mod*inv[m]%Mod;
}
int find_val(int n,int k){
	k=n-k;
	int ans=0;
	for(int i=0;i<=k;i++){
		ans=(ans+1ll*C(n-1+i,k+i)*C(n+k,k-i)%Mod*S[i+k][i]%Mod*((!((k-i)&1))?1:Mod-1))%Mod;
	}
	return ans;
}
int ans[Maxk+5];
int main(){
	init();
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k&&i<n;i++){
		ans[i]=find_val(n,n-i);
	}
	for(int i=2;i<=k;i++){
		ans[i]=(ans[i]+ans[i-2])%Mod;
	}
	for(int i=1;i<=k;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}