#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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

const int N = 1e6+10, mod = 1e9+7;
inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}
int fac[N],ifac[N];
inline void init(int n){
	fac[0]=1;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=power(fac[n],mod-2);
	Dow(i,n-1,0) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
inline int C(int n,int m){
	if (n<m||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

inline void solve(){
	int n=read(),k=read();
	int ans=fac[n];
	for (int i=1;i<=n&&1ll*(i-1)*k+1<=n;++i) ans=(ans+1ll*C(n-1-(i-1)*k+i,i)*fac[i]%mod*fac[n-i])%mod;
	printf("%d\n",1ll*ans*ifac[n]%mod);
}

int main(){
	init(1e6);
	int T=read();
	while (T--) solve();
}