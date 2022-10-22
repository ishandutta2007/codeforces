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
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,k;
int a[1010];
const int mod=998244353;
int maxn;
int ans;
int pre[1010];
int dp[1010][1010];
int solve(int x){
	for(int i=1;i<=k;++i) pre[i]=0;
	int p=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j) dp[i][j]=0;
	int res=0;
	dp[1][1]=1;
	for(int i=2;i<=n;++i){
		while(a[i]-a[p]>=x){
			for(int j=1;j<=k;++j) pre[j]=(pre[j]+dp[p][j])%mod;
			++p;
		}
		dp[i][1]=1;
		for(int j=2;j<=k;++j) dp[i][j]=pre[j-1];
		res=(res+dp[i][k])%mod;
	}
	return res;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read(),maxn=max(maxn,a[i]);
	sort(a+1,a+n+1);
	for(int x=1;x*(k-1)<=maxn;++x){
		ans=(ans+solve(x))%mod;
	}
	print(ans);
	putchar('\n');
	return 0;
}