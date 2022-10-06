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

const int N = 666666;
ll res;ll ff(ll x){return x*x;}
ll solve(Vi a, Vi b, Vi c){
	for(int x:b){
		bool gg=0;
		int y=lower_bound(ALL(c),x)-c.begin();
		if(y<SZ(c))y=c[y];else gg=1;
		int z=upper_bound(ALL(a),x)-a.begin();
		if(!z)gg=1;else z=a[z-1];
		if(!gg)umin(res,ff(z-x)+ff(z-y)+ff(y-x));
	}
	
	return 8e18;
}
int main() {
	int T;read(T);while(T--){
		int n1,n2,n3;
		read(n1);read(n2);read(n3);
		Vi a,b,c;int x;
		while(n1--)read(x),a.pb(x);
		while(n2--)read(x),b.pb(x);
		while(n3--)read(x),c.pb(x);
		sort(ALL(a));sort(ALL(b));sort(ALL(c));
		res=8e18;
		umin(res,solve(a,b,c));
		umin(res,solve(a,c,b));
		umin(res,solve(b,a,c));
		umin(res,solve(b,c,a));
		umin(res,solve(c,a,b));
		umin(res,solve(c,b,a));
		printf("%lld\n",res);
	}
	return 0;
}