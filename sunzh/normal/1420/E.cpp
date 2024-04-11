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
int a[110];
int k;
int f[100],sum[100];
int cnt0;
int dp[85][85][6500];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	a[0]=a[n+1]=1;
	for(int i=1;i<=n+1;++i){
		int st=i;
		while(i<=n+1&&a[i]==0) ++i;
		f[++k]=i-st;
		sum[k]=sum[k-1]+f[k];
		cnt0+=f[k];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<k;++i){
		for(int j=0;j<=cnt0;++j){
			for(int h=0;h<=((n*n-1)>>1);++h){
				if(dp[i][j][h]>=0x153f3f3f) continue ;
				for(int d=0;d+j<=cnt0;++d) dp[i+1][j+d][h+abs(d+j-sum[i+1])]=min(dp[i+1][j+d][h+abs(d+j-sum[i+1])],dp[i][j][h]+d*d);
			}
		}
	}
	int minn=0x7f7f7f7f;
	for(int i=0;i<=(n*(n-1)>>1);++i){
		minn=min(minn,dp[k][cnt0][i]);
		int ans=(cnt0*cnt0-minn)>>1;
		print(ans);
		printf(" ");
	}
}
//xscakioi