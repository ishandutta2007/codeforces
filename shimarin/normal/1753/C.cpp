#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N = 2e5+10, mod = 998244353;
int n,a[N];

int fac[N],ifac[N];
inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}
inline void init(int n){
	fac[0]=1;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=power(fac[n],mod-2);
	Dow(i,n-1,0) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}

int pre[N],suf[N];
inline void solve(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) pre[i]=pre[i-1]+(a[i]==1);
	suf[n+1]=0;
	Dow(i,n,1) suf[i]=suf[i+1]+(a[i]==0);
	int ans=0,all=1ll*n*(n-1)/2%mod;
	int i=suf[1],t=min(pre[i],suf[i+1]);
	For(j,1,t) ans=(ans+1ll*all*power(1ll*(pre[i]-j+1)*(suf[i+1]-j+1)%mod,mod-2))%mod;
	printf("%d\n",ans);
}

int main(){
	init(2e5);
	int T=read();
	while (T--) solve();
}