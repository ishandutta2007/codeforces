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

const int N = 1e5+10;
poly v[N];
int d[N];
inline void init(int n){
	For(i,1,n)
		For(j,1,n/i) v[i*j].pb(i);
	For(i,1,n) d[i]=siz(v[i]);
}

inline int calc(int x){
	return x*(x-1);
}
inline void solve(){
	int a=read(),b=read(),c=read();
	int ga=__gcd(b,c);
	int gb=__gcd(a,c);
	int gc=__gcd(a,b);
	int gg=__gcd(gc,c);
	int ans=d[a]*d[b]*d[c];
	ans-=((d[a]*calc(d[ga])+d[b]*calc(d[gb])+d[c]*calc(d[gc]))/2);
	ans+=(calc(d[gg])*(d[gg]-2)/3*2);
	ans+=(calc(d[gg])*(d[ga]+d[gb]+d[gc]-3*d[gg]+2)/2);
	ans-=(d[ga]-d[gg])*(d[gb]-d[gg])*(d[gc]-d[gg]);
	printf("%d\n",ans);
}

int main(){
	init(1e5);
	int T=read();
	while (T--) solve();
}