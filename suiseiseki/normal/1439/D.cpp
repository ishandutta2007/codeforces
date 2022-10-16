#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int abs(int a){
	return a<0?-a:a;
}
const int Maxn=500;
int n,m,Mod;
int C[Maxn+5][Maxn+5];
void init(){
	C[0][0]=1;
	for(int i=1;i<=Maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
}
int f_1[Maxn+5],f_2[Maxn+5];
int f_3[Maxn+5][Maxn+5],f_4[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d%d",&n,&m,&Mod);
	init();
	f_1[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f_1[i]=(f_1[i]+1ll*f_1[i-j]*f_1[j-1]%Mod*C[i-1][j-1])%Mod;
		}
		f_1[i]=1ll*f_1[i]*(i+1)%Mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int sum=0;
			for(int k=1;k<=i;k++){
				sum+=abs(k-j);
			}
			f_2[i]=(f_2[i]+(1ll*j*(j-1)/2+1ll*(i-j)*(i-j+1)/2)%Mod*f_1[j-1]%Mod*f_1[i-j]%Mod*C[i-1][j-1])%Mod;
			f_2[i]=(f_2[i]+1ll*f_2[j-1]*f_1[i-j]%Mod*C[i-1][j-1]%Mod*(i+1))%Mod;
			f_2[i]=(f_2[i]+1ll*f_2[i-j]*f_1[j-1]%Mod*C[i-1][j-1]%Mod*(i+1))%Mod;
		}
	}
	f_3[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,m);j++){
			f_3[i][j]=f_3[i-1][j];
			for(int k=1;k<=j;k++){
				if(i-1-k>=0){
					f_3[i][j]=(f_3[i][j]+1ll*f_1[k]*f_3[i-1-k][j-k]%Mod*C[j][k])%Mod;
				}
				else{
					f_3[i][j]=(f_3[i][j]+1ll*f_1[k]*C[j][k])%Mod;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,m);j++){
			f_4[i][j]=f_4[i-1][j];
			for(int k=1;k<=j;k++){
				if(i-1-k>=0){
					f_4[i][j]=(f_4[i][j]+(1ll*f_3[i-1-k][j-k]*f_2[k]+1ll*f_4[i-1-k][j-k]*f_1[k])%Mod*C[j][k])%Mod;
				}
				else{
					f_4[i][j]=(f_4[i][j]+1ll*f_2[k]*C[j][k])%Mod;
				}
			}
		}
	}
	printf("%d\n",f_4[n][m]);
	return 0;
}