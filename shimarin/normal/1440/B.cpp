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

const int N = 2e5+10;
int n,k,a[N];
inline void solve(){
	n=read(),k=read();
	For(i,1,n*k) a[i]=read();
	ll ans=0;
	int l1=0,l2=0;
	if (n%2==0) l1=n/2-1;
		else l1=n/2;
	l2=n-l1;
	int l=1,r=n*k;
	For(i,1,k){
		ans+=a[r-l2+1];
		l+=l1,r-=l2;
	}
	printf("%lld\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}