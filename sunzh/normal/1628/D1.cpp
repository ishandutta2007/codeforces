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
int dp[2010][2010];
int T;
int n,m,k;
const int mod=1e9+7;
int main(){
	T=read();
	for(int i=0;i<=2000;++i) dp[i][0]=0,dp[i][i]=i;
	for(int i=1;i<=2000;++i){
		for(int j=1;j<i;++j){
			dp[i][j]=1ll*(dp[i-1][j-1]+dp[i-1][j])*(mod+1>>1)%mod;
		}
	}
	while(T--){
		n=read(),m=read(),k=read();
		printf("%d\n",1ll*dp[n][m]*k%mod);
	}
}