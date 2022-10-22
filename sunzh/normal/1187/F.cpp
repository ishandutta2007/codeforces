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
#define int long long
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
const int mod=1e9+7;
int l[200010],r[200010];
int P[200010];
int sum,ans;
inline int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) l[i]=read();
	for(int i=1;i<=n;++i) r[i]=read();
	for(int i=2;i<=n;++i) P[i]=1ll*max(0ll,1ll*min(r[i],r[i-1])-max(l[i],l[i-1])+1)*qpow(1ll*(r[i-1]-l[i-1]+1)*(r[i]-l[i]+1)%mod,mod-2)%mod;
	for(int i=1;i<=n;++i) P[i]=(1-P[i]+mod)%mod;
	for(int i=1;i<=n;++i) (sum+=P[i])%=mod;
	for(int i=1;i<=n;++i){
		if(i>=2) (ans+=2ll*(1-1+P[i]-1+P[i-1]+1ll*max(0ll,min(r[i],min(r[i-1],r[i-2]) ) - max(l[i],max(l[i-1],l[i-2]) )+1) *
		qpow(1ll*(r[i-2]-l[i-2]+1)*(r[i-1]-l[i-1]+1)%mod*(r[i]-l[i]+1)%mod,mod-2)+mod)%mod)%=mod;
		(ans+=P[i]+1ll*P[i]*(sum-P[i]-P[i-1]-P[i+1])%mod)%=mod;
	}
	print((ans+mod)%mod);
}