#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 266666,LIM=35,mo=998244353;
int n,m;ll a[66];int g[N],ans[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}

int fac[N],ifac[N];
void iniC(int n){// 
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
inline int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}
int popcnt(ll s){int x=0;while(s)x++,s^=s&-s;return x;}

ll b[N];int cnt;


int main() {
	iniC(N-1);read(n);read(m);
	rep(i,1,n){
		ll x;read(x);
		per(j,LIM,0)if(x>>j&1){
			if(!a[j]){a[j]=x;break;}
			x^=a[j];
		}
	}
	/*rep(s,0,(1<<m)-1){
		bool ok=1;
		rep(i,0,LIM)ok&=(popcnt(a[i]&s)%2==0);
		if(ok)add(g[popcnt(s)],1);
	}*/
	
	rep(i,0,LIM)if(a[i])b[++cnt]=a[i];
	int blo=m/2;vector<Pll>c;//,d;
	rep(s,0,(1<<blo)-1){
		ll x=0;rep(i,1,cnt)x+=(ll)(popcnt(b[i]&s)%2)<<i;
		c.pb(mp(x,-popcnt(s)-1));
	}
	rep(s,0,(1<<m-blo)-1){
		ll x=0;rep(i,1,cnt)x+=(ll)(popcnt(b[i]&((ll)s<<blo))%2)<<i;
		c.pb(mp(x,popcnt(s)+1));
	}
	sort(ALL(c));//sort(ALL(d));
//	rep(i,0,SZ(c)-1)printf("%lld %lld\n",c[i].fi,c[i].se);
	rep(i,0,SZ(c)-1){
		int j=i;while(j+1<SZ(c)&&c[j+1].fi==c[i].fi)j++;
		int cnt[55]={0};
		rep(k,i,j)if(c[k].se<0)cnt[-c[k].se-1]++;else{
			rep(x,0,m)if(cnt[x])add(g[x+c[k].se-1],cnt[x]);
		}
		i=j;
	}
	
//	rep(cnt,0,m)printf("%d ",g[cnt]);puts("");
	rep(cnt,0,m)rep(sz,0,m)rep(i,0,cnt)add(ans[cnt],1ll*g[sz]*C(sz,i)%mo*C(m-sz,cnt-i)%mo*(i&1?mo-1:1)%mo);
	rep(cnt,0,m)printf("%lld ",1ll*ans[cnt]*power(2,n-m+mo-1)%mo);
	return 0;
}