#include <cstdio>
#define Maxn 4000
#define Mod 998244353
#define ll long long
int fk(int x){
	if(x>=Mod){
		return x-Mod;
	}
	return x;
}
int maxn(int a,int b){
	return a>b?a:b;
}
int n,m,K,Ans;
int fac[Maxn+5],C[Maxn+5][Maxn+5];
int f[Maxn+5][Maxn+5],g[Maxn+5][Maxn+5];
bool px[Maxn+5],py[Maxn+5];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	int mx=maxn(n,m);
	fac[0]=1;
	for(int i=1;i<=mx;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	for(int i=0;i<=mx;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=fk(C[i-1][j-1]+C[i-1][j]);
		}
	}
	int a,b,c,d;
	for(int i=1;i<=K;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		px[a]=px[c]=1;
		py[b]=py[d]=1;
	}
	int cntx=0,cnty=0;
	for(int i=1;i<=n;i++){
		cntx+=px[i];
	}
	for(int i=1;i<=m;i++){
		cnty+=py[i];
	}
	for(int i=0;i<=n;i++){
		f[i][0]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=mx;j++){
			if(px[i]||px[i-1]){
				f[i][j]=f[i-1][j];
			}
			else{
				f[i][j]=fk(f[i-1][j]+f[i-2][j-1]);
			}
		}
	}
	for(int i=0;i<=m;i++){
		g[i][0]=1;
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=mx;j++){
			if(py[i]||py[i-1]){
				g[i][j]=g[i-1][j];
			}
			else{
				g[i][j]=fk(g[i-1][j]+g[i-2][j-1]);
			}
		}
	}
	for(int i=0;i<=mx;i++){
		for(int j=0;j<=mx;j++){
			if(i+(j<<1)<=n-cntx&&(i<<1)+j<=m-cnty){
				Ans=fk(Ans+1ll*f[n][j]*C[n-cntx-(j<<1)][i]%Mod*g[m][i]%Mod*C[m-cnty-(i<<1)][j]%Mod*fac[i]%Mod*fac[j]%Mod);
			}
		}
	}
	printf("%d\n",Ans);
	return 0;
}