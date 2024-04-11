#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
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
int n;
int dp[1000010];
int r1,r2,r3,d;
int a[1000010];
signed main(){
	n=read(),r1=read(),r2=read(),r3=read(),d=read();
	for(int i=1;i<=n;++i) a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;dp[1]=min(r1*a[1]+r3,min(r2+r1,r1*(a[1]+2))+d+d);
	for(int i=2;i<=n;++i){
		dp[i]=dp[i-1]+min(r1*a[i]+r3,min(r2+r1,r1*(a[i]+2))+d+d);
		dp[i]=min(dp[i],dp[i-2]+min(r1*(a[i-1]+2),r2+r1)+min(r1*(a[i]+2),r2+r1)+d+d);
	}
	print(min(dp[n],dp[n-2]+min(r1*(a[n-1]+2),r2+r1)+d+min(r1*a[n]+r3,min(r2+r1,r1*(a[n]+2))+d+d))+d*(n-1));
	return 0;
}