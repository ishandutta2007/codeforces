#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,a[200010];
int dp[200010][2][2];
const int mod=1e9+7;
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	// dp[0][0]=1;
	int ans=0;
	for(int i=0;i<31;++i){
		memset(dp,0,sizeof(dp));dp[0][0][0]=1;
		for(int j=1;j<=n;++j){
			for(int _=0;_<2;++_) for(int __=0;__<2;++__) dp[j][_][__]=dp[j-1][_][__];
			if(((a[j]>>i)<<i)==a[j]){
				for(int _=0;_<2;++_){
					for(int __=0;__<2;++__)	(dp[j][_|(a[j]>>i&1)][__^(a[j]>>i&1)]+=dp[j-1][_][__])%=mod;
				}
			}
		}
		// if(i!=0){
		// 	for(int j=1;j<=n;++j) if(((a[j]>>i)<<i)==a[j]) ans-=(a[j]>>i&1);
		// }
		(ans+=dp[n][1][0])%=mod;
		if(i==0) (ans+=dp[n][1][1])%=mod;
	}
	printf("%d\n",ans);
}