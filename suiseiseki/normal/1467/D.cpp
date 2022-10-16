#include <cstdio>
const int Maxn=5000;
const int Mod=1000000007;
int n,k;
int q;
int f[Maxn+5][Maxn+5];
int g[Maxn+5][Maxn+5];
int sum[Maxn+5];
int a[Maxn+5];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++){
		g[i][0]=1;
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			if(i<n){
				g[i][j]=(g[i][j]+g[i+1][j-1])%Mod;
			}
			if(i>1){
				g[i][j]=(g[i][j]+g[i-1][j-1])%Mod;
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][k]=1;
		sum[i]=g[i][k];
	}
	for(int j=k-1;j>=0;j--){
		for(int i=1;i<=n;i++){
			if(i<n){
				f[i][j]=(f[i][j]+f[i+1][j+1])%Mod;
			}
			if(i>1){
				f[i][j]=(f[i][j]+f[i-1][j+1])%Mod;
			}
			sum[i]=(sum[i]+1ll*g[i][j]*f[i][j])%Mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=(ans+1ll*a[i]*sum[i])%Mod;
	}
	for(int i=1;i<=q;i++){
		int x,v;
		scanf("%d%d",&x,&v);
		ans=(ans-1ll*a[x]*sum[x]%Mod+Mod)%Mod;
		a[x]=v;
		ans=(ans+1ll*a[x]*sum[x])%Mod;
		printf("%d\n",ans);
	}
	return 0;
}