#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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

const int N = 1e5+10, mod = 998244353;
int n,a[N],c[N][11],b[N],cnt[11];

inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	For(i,1,n){
		b[i]=0;
		for (int j=a[i];j;c[i][++b[i]]=j%10,j/=10);
		cnt[b[i]]++;
	}
	ll ans=0;
	For(i,1,n){
		ll y=1;
		For(j,1,b[i]){
			ll x=y;
			y*=100;
			Dow(k,b[n],1){
				ans=(ans+x%mod*c[i][j]%mod*cnt[k])%mod;
				if (k<=j-1) x/=10;
			}
		}
	}
	int inv10=power(10,mod-2);
	For(i,1,n){
		ll y=10;
		For(j,1,b[i]){
			ll x=y;
			y*=100,y%=mod;
			Dow(k,b[n],1){
				ans=(ans+x%mod*c[i][j]%mod*cnt[k])%mod;
				if (k<=j) x=x*inv10%mod;
			}
		}
	}
	printf("%lld\n",ans);
}