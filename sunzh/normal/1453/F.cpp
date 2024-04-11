#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[3010];
int dp[3010][3010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=2;i<=n;++i){
			for(int j=i-1;j<=n;++j) dp[i][j]=0x3f3f3f3f;
		}
		for(int i=2;i<=n;++i){
			int cnt=0;
			for(int j=i-1;j;--j){
				if(j+a[j]>=i) dp[i][j+a[j]]=min(dp[i][j+a[j]],dp[j][i-1]+cnt),++cnt;
			}
//			if(!cnt) dp[i][i]=min(dp[i][i],cnt);
//			printf("i:%d,cnt:%d\n",i,cnt);
			for(int j=i;j<=n;++j){
				dp[i][j]=min(dp[i][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}