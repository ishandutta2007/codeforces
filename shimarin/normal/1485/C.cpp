#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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

inline void solve(){
	int n=read(),m=min(read(),(ll)n-1);
	ll ans=0;
	For(i,3,min(50000,m+1)) ans+=min(n/i,i-2);
	int l=50001,r;
	for (;l<=m+1;l=++r){
		r=min(m+1,n/(n/l));
		ans+=1ll*(n/l)*(r-l+1);
	}
	printf("%lld\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
//	For(j,1,100) For(i,1,100) if (i%j==i/j) printf("%d %d\n",i,j);
}