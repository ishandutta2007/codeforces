//    
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

const int N = 5e5+10;
int n,m;
ll a[N];
vector<int>v[N];
map<vector<int>,ll>f;
inline void solve(){
	n=read(),m=read(),f.clear();
	For(i,1,n) a[i]=read(),v[i].clear();
	For(i,1,m){
		int x=read(),y=read();
		v[y].pb(x);
	}
	For(i,1,n) sort(all(v[i]));
	For(i,1,n){
		if (v[i].empty()) continue;
	//	if (siz(v[i])==1){f[mp(v[i][0],v[i][0])]+=a[i];continue;}
	//	FOR(j,0,siz(v[i])-1) f[mp(v[i][j],v[i][j+1])]+=a[i];
		f[v[i]]+=a[i];
	}
	ll ans=0;
	for (auto it=f.begin();it!=f.end();++it) ans=(!ans?(*it).se:__gcd((*it).se,ans));
	printf("%lld\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}