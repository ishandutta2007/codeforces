#include<cstdio>
const int N=1000005,p=1000000007;
int n,x,y,dp[N],f[N],rf[N];
int fpw(int a,int x){
	int ans=1;
	for(;x;x>>=1,a=1ll*a*a%p)if(x&1)ans=1ll*ans*a%p;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,p;i<=n;i++){
		scanf("%d",&p);
		if(p==1)x++;else y++;
	}
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=1ll*i*f[i-1]%p;
	rf[n]=fpw(f[n],p-2);
	for(int i=n;i;i--)rf[i-1]=1ll*rf[i]*i%p;
	dp[0]=1;
	for(int i=1;i<=n;i++)
		dp[i]=(dp[i-1]+(i-1ll)*dp[i-2])%p;
	printf("%d\n",(int)(1ll*dp[x]*f[x+y]%p*rf[x]%p));
}