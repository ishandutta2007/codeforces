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
int n;
int a[200010];
PII stk[200010];
int top;
int nws;
const int mod=998244353;
int dp[200010];
int main(){
	n=read();dp[0]=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		PII nw=mp(a[i],dp[i-1]);
		while(top&&stk[top].fi>=a[i]){
			(nw.se+=stk[top].se)%=mod;(nws-=1ll*stk[top].se*stk[top].fi%mod)%=mod;--top;
		}
		stk[++top]=nw;(nws+=1ll*nw.fi*nw.se%mod)%=mod;
		dp[i]=(mod-nws)%mod;
	}
	printf("%d\n",((n&1)?(mod-dp[n])%mod:dp[n]));
}