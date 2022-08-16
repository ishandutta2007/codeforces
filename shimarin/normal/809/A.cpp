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

const int N = 3e5+10, mod = 1e9+7;
int n,a[N],ans,pw[N];

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	pw[0]=1;
	For(i,1,n) pw[i]=1ll*pw[i-1]*2%mod;
	For(i,1,n) ans=(ans+1ll*(mod-a[i])*pw[n-i])%mod;
	For(i,1,n) ans=(ans+1ll*a[i]*pw[i-1])%mod;
	printf("%d\n",ans);
}