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

const int N = 2e6+10;
int n,m,a[N],b[N],g,pos[N],cnt[N];
ll k,lll;
inline void init(){
	fil(pos,-1);
	FOR(i,0,m) pos[b[i]]=i;
	FOR(i,0,n) if (~pos[a[i]]) ++cnt[(i-pos[a[i]]+n)%n];
}
inline int nxt(int x){
	return x==n-1?0:x+1;
}
inline bool check(ll t){
	ll ans=0,lim=t/lll,p=0,tmp=t;
	while (233){
		ans+=lim*cnt[p],p=(p+m)%n,t-=lim*m;
		if (p==0) break;
	}
	while (233){
		if (t<m){
			int c=0,i=p;
			while (t--){
				ans+=(b[c]==a[i]);
				++c,i=nxt(i);
			}
			break;
		}
		ans+=cnt[p],p=(p+m)%n,t-=m;
	}
	return tmp-ans>=k;
}
int main(){
	n=read(),m=read(),k=read();
	lll=1ll*n*m/__gcd(n,m);
	FOR(i,0,n) a[i]=read();
	FOR(i,0,m) b[i]=read();
	if (n<m) swap(n,m),swap(a,b);
	init();
	ll l=0,r=max(n,m)*k,ans=0;
	while (l<=r){
		ll mid=l+r>>1;
		if (check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
	}
	printf("%lld\n",ans);
}