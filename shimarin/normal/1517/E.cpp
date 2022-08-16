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
const int N = 2e5+10, mod = 998244353;
int n;
ll a[N],pre1[N],pre2[N],pre0[N];
inline bool check(ll t,int i,int mid){
	if (i&1) return pre0[n]-2*pre0[i]+2*(pre2[i]-pre2[mid-1])>-t;
	return pre0[n]-2*pre0[i]+2*(pre1[i]-pre1[mid-1])>-t;
}
inline int Find(ll t,int l,int r,int i){
	int ret=0;
	while (l<r){
		int mid=l+r>>1;
		if (check(t,i,mid)) ret=mid,l=mid+1;
			else r=mid;
	}
	return ret;
}
inline int calc(ll t,int z0,int z1){
	int ret=0,k=n;
	if (!z1) --k;
	if (!(z0&&!z1)&&pre0[n]>-t) ++ret;
	For(i,1,k){
		int tp=Find(t,1,i+2,i);
		ret=(ret+(tp+1>>1))%mod;
		if (tp>=1&&z0&&(i%2==0)) ret=(ret+mod-1)%mod;
	}
	return ret;
}
inline void init(){
	For(i,1,n) pre0[i]=pre0[i-1]+a[i],pre1[i]=pre1[i-1]+(i&1?a[i]:0),pre2[i]=pre2[i-1]+(i&1?0:a[i]);
}
inline int fix(ll x,ll y){
	int ans=0;
	For(i,0,n) if (2*pre0[i]>pre0[n]-x+y) ans=(ans+1)%mod;
	return ans;
}
ll x,y;
inline void solve(){
	n=read(),x=read();
	if (n==1) return printf("%d\n",1),void(0);
	n-=2;
	For(i,1,n) a[i]=read();
	y=read();
	init();
	int ans=calc(x-y,1,0);
	ans=(ans+calc(-x-y,0,0))%mod;
	ans=(ans+calc(-x+y,0,1))%mod;
	ans=(ans+calc(x+y,1,1))%mod;
	ans=(ans+fix(x,y))%mod;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while (T--) solve();
}