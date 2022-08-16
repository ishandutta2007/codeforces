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

const int N = 1e5+10, mod = 1e9+7;
int n,m,a[N],b[N],suf[N],pw[N<<1];

inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}

int main(){
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) b[i]=read();
	Dow(i,n,1) suf[i]=suf[i+1]+(a[i]==0)+(b[i]==0);
	pw[0]=1;
	For(i,1,suf[1]) pw[i]=1ll*pw[i-1]*m%mod;
	int x=0;
	For(i,1,m) x=(x+m-i)%mod;
	int ans=0,cnt=1;
	For(i,1,n){
		if (a[i]==0&&b[i]){
			ans=(ans+1ll*pw[suf[i+1]]*(m-b[i])%mod*cnt)%mod;
		} else if (a[i]&&b[i]==0){
			ans=(ans+1ll*pw[suf[i+1]]*(a[i]-1)%mod*cnt)%mod;
		} else if (a[i]==0&&b[i]==0){
			ans=(ans+1ll*pw[suf[i+1]]*cnt%mod*x)%mod;
			cnt=1ll*cnt*m%mod;
		} else {
			if (a[i]==b[i]) continue;
			if (a[i]>b[i]){
				ans=(ans+1ll*pw[suf[i+1]]*cnt)%mod;
				break;
			} else {
				break;
			}
		}
	}
	printf("%d\n",1ll*ans*power(pw[suf[1]],mod-2)%mod);
}