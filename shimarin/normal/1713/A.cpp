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

inline void solve(){
	int n=read();
	int mxx=0,mnx=0;
	int mxy=0,mny=0;
	For(i,1,n){
		int x=read(),y=read();
		mxx=max(mxx,x),mnx=min(mnx,x);
		mxy=max(mxy,y),mny=min(mny,y);
	}
	printf("%lld\n",2ll*(mxx-mnx+mxy-mny));
}

int main(){
	int T=read();
	while (T--) solve();
}