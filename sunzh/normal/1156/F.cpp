#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[5010];
int dp[5010][5010];
int sum[5010];
const int mod=998244353;
inline int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int ans;
int L[5010],R[5010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		L[i]=lower_bound(a+1,a+n+1,a[i])-a;
		R[i]=upper_bound(a+1,a+n+1,a[i])-a;
	}
	for(int i=1;i<=n;++i) dp[1][i]=qpow(n,mod-2);
	for(int i=2;i<=n;++i){
		int inv=qpow(n-i+1,mod-2);
		for(int j=1;j<=n;++j) sum[j]=(sum[j-1]+dp[i-1][j])%mod;
		for(int j=1;j<=n;++j){
			int k=L[j];
			dp[i][j]=1ll*inv*sum[k-1]%mod;
			int p=R[j];
			(ans+=1ll*(sum[p-1]-sum[k-1]-dp[i-1][j]+mod)%mod*inv%mod)%=mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
}