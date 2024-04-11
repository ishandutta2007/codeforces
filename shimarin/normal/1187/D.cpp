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
 
const int N = 3e5+10;
int n,cnt[N],t[N],pos[N];
pa a[N],b[N];
 
int c[N];
inline void Add(int x,int y){
	for (;x<=n;x+=x&-x) c[x]=max(c[x],y);
}
inline int Query(int x){
	int ret=0;
	for (;x;x-=x&-x) ret=max(ret,c[x]);
	return ret;
}
inline void solve(){
	n=read();
	For(i,1,n) cnt[i]=c[i]=0;
	For(i,1,n) a[i]=mp(read(),i),++cnt[a[i].fi],t[i]=a[i].fi;
	For(i,1,n) b[i]=mp(read(),i),--cnt[b[i].fi];
	For(i,1,n) if (cnt[i]) return puts("NO"),void(0);
	sort(a+1,a+1+n),sort(b+1,b+1+n);
	For(i,1,n) pos[a[i].se]=b[i].se;
	For(i,1,n){
		if (Query(t[i]-1)>pos[i]) return puts("NO"),void(0);
		Add(t[i],pos[i]);
	}
	puts("YES");
}
 
int main(){
	int T=read();
	while (T--) solve();
}