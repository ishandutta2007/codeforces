#include <cstdio>
#define ll long long
#define Mod 1000000007
#define Maxn 1000
ll f[Maxn+5][Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		f[i][0]=1;
	}
	int ans=(n+1)>>1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=(f[i-1][j]+f[i][j-1])%Mod;
			if((i+j)&1){
				ans+=f[i][j];
				ans%=Mod;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}