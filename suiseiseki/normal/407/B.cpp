#include <cstdio>
#define Maxn 1000000
#define Mod 1000000007
int dp[Maxn+5];
int pre[Maxn+5];
int p[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	dp[1]=pre[1]=2;
	for(int i=2;i<=n;i++){
		dp[i]=pre[i-1]-pre[p[i]-1]+2;
		if(dp[i]<0){
			dp[i]+=Mod;
		}
		pre[i]=pre[i-1]+dp[i];
		pre[i]%=Mod;
	}
	printf("%d\n",pre[n]);
	return 0;
}