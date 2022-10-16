#include <cstdio>
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
const int Maxn=5100;
const int Maxm=100;
const int Mod=998244353;
int C[Maxn+5][Maxm+5];
int inv[Maxn+5];
int s,r,p;
void init(){
	C[0][0]=1;
	for(int i=1;i<=Maxn;i++){
		if(i<=Maxm){
			C[i][i]=1;
		}
		C[i][0]=1;
		for(int j=1;j<i&&j<=Maxm;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	inv[1]=1;
	for(int i=2;i<=Maxn;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
int calc(int n,int m,int x){
	int ans=0;
	for(int i=0;i<=m&&i*x<=n;i++){
		if(!(i&1)){
			ans=(ans+1ll*C[m][i]*C[n-x*i+m-1][m-1])%Mod;
		}
		else{
			ans=(ans-1ll*C[m][i]*C[n-x*i+m-1][m-1]%Mod+Mod)%Mod;
		}
	}
	return ans;
}
int main(){
	init();
	scanf("%d%d%d",&p,&s,&r);
	int sum_1=0,sum_2=0;
	for(int x=r;x<=s;x++){
		if(x*p<s){
			continue;
		}
		for(int i=1;i<=p;i++){
			if(i*x>s||(p-i)*(x-1)+i*x<s){
				continue;
			}
			if(i==p){
				if(i*x==s){
					sum_2=(sum_2+inv[i])%Mod;
				}
				continue;
			}
			sum_2=(sum_2+1ll*C[p-1][i-1]*calc(s-i*x,p-i,x)%Mod*inv[i])%Mod;
		}
	}
	sum_1=C[s-r+p-1][p-1];
	int ans=1ll*sum_2*quick_power(sum_1,Mod-2,Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}