#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[300010];
int dp[300010][41];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		int d=a[i]/1000,d1=d*10;
		for(int j=0;j<=40;++j){
			if(j>=d)dp[i][j]=min(dp[i][j],dp[i-1][j-d]+a[i]);
			for(int k=0;k<=d1&&k+j<=40;++k) dp[i][j]=min(dp[i][j],dp[i-1][j+k]+a[i]-k*100);
			if(i==n) ans=min(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}