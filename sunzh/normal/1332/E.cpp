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
#define int long long
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
int n,m,l,r;
const int mod=998244353;
inline int qpow(int x,int k){
	int res=1;
	x%=mod;
	while(k){
		if(k&1) res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
signed main(){
	n=read(),m=read(),l=read(),r=read();
	int odd=(r-l+1>>1)+(((r-l+1)&1)?(l&1):0);
	if(r-l+1-odd==0||odd==0){
		printf("%lld\n",qpow(r-l+1,n*m));return 0;
	}
	int ans=0;
	if(((n*m)&1)^1)ans=(qpow(r-l+1,n*m)+qpow(r-l+1-2*odd,n*m)+mod)%mod*qpow(2,mod-2)%mod;
	else ans=qpow(r-l+1,n*m);
	ans%=mod;
	printf("%lld\n",ans);
	return 0;
}