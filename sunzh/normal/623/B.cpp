#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,A,B;
int a[1000010];
int fac[100];
int tot,cnt;
bool vis[1000010];
int prime[1000010];
long long cst[1000010],dp[1000010][3];
void get_prime(){
	for(int i=2;i<=1000000;++i){
		if(!vis[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<=1000000;++j){
			vis[i*prime[j]]=0;
			if(i%prime[j]==0) break ;
		}
	}
}
void get_fac(int x){
	if(x==1) return ;
	int t=x;
	for(int i=1;i<=tot;++i){
		if(x%prime[i]==0){
			fac[++cnt]=prime[i];
			x=x/prime[i];
		}
	}
	if(x==t) fac[++cnt]=x;
}
long long solve(int x){
	for(int i=1;i<=n;++i){
		if(a[i]%x==0) cst[i]=0;
		else if((a[i]+1)%x==0||(a[i]-1)%x==0) cst[i]=B;
		else cst[i]=0x3f3f3f3f3f3f3ff;
	}
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	for(int i=1;i<=n;++i){
		if(cst[i]<=0x3f3f3f3f){
			dp[i][0]=dp[i-1][0]+cst[i];dp[i][2]=min(dp[i-1][2],dp[i-1][1])+cst[i];
		}
		else{
			dp[i][0]=dp[i][2]=0x3f3f3f3f3f3f3ff;
		}
		dp[i][1]=min(dp[i-1][1],dp[i-1][0])+A;
	}
	return min(dp[n][0],min(dp[n][1],dp[n][2]));
}
int main(){
	get_prime();
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;++i) a[i]=read();
	get_fac(a[1]-1);get_fac(a[1]);get_fac(a[1]+1);
	get_fac(a[n]-1);get_fac(a[n]);get_fac(a[n]+1);
	sort(fac+1,fac+cnt+1);
	cnt=unique(fac+1,fac+cnt+1)-fac-1;
	long long ans=0x7f7f7f7f7f7f7f7f;
	for(int i=1;i<=cnt;++i) ans=min(ans,solve(fac[i]));
	printf("%lld\n",ans);
	return 0;
}