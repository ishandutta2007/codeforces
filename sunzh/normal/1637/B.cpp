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
int T;
int n;
int a[110];
int dp[110][110];
int mex[110][110];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		long long ans=0;
		memset(dp,0,sizeof(dp));
		memset(mex,0,sizeof(mex));
		for(int i=1;i<=n;++i){
			set<int>st;
			for(int j=i;j<=n;++j){
				st.insert(a[j]);
				for(int t=0;t<=n+1;++t){
					if(!st.count(t)){
						mex[i][j]=t;break ;
					}
				}
			}
		}
		for(int i=1;i<=n;++i){
			dp[i][i-1]=0;
			for(int j=i;j<=n;++j){
				for(int t=j-1;t>=i-1;--t){
					dp[i][j]=max(dp[i][j],dp[i][t]+1+mex[t+1][j]);
				}
				ans+=dp[i][j];
			}
		}
		printf("%lld\n",ans);
	}
}