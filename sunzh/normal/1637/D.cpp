#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<bitset>
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
int a[110],b[110];
bitset<20010>dp;
int main(){
	T=read();
	while(T--){
		dp.reset();
		n=read();
		int sum=0;
		for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i];
		for(int i=1;i<=n;++i) b[i]=read(),sum+=b[i];
		long long ans=1e18;dp[0]=1;
		for(int i=1;i<=n;++i){
			dp=(dp<<a[i])|(dp<<b[i]);
		}
		for(int i=0;i<=sum;++i) if(dp[i]){
			ans=min(ans,1ll*i*i+1ll*(sum-i)*(sum-i));
		}
		for(int i=1;i<=n;++i) ans+=1ll*(n-2)*a[i]*a[i]+1ll*(n-2)*b[i]*b[i];
		printf("%lld\n",ans);
	}
}