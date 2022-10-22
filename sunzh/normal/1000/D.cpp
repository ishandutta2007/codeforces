#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int inline read(){
	int num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*neg;
}
int n;
long long dp[10010],c[1010][1010];
int a[10010];
long long ans;
const int mod=998244353;
int main(){
	for(int i=1;i<=1001;++i){
		c[i][0]=1,c[i][i]=1;
		for(int j=1;j<i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	dp[n+1]=1;
	for(int i=n;i>=1;--i){
		if(a[i]<=0) continue ;
		int j=i+a[i]+1;
		for(j;j<=n+1;++j){
			dp[i]=(dp[i]+dp[j]*c[j-i-1][a[i]])%mod;
		}
		ans=(ans+dp[i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}