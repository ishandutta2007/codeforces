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
ll calc(ll n){
	ll res=0;
	rep(i,0,60)if(n>>i&1){
		if(i&1){res^=1ll<<i-1;res^=1ll<<i;}
		else{res^=1ll<<i+1;}
	}
	return res;
}
ll solve(ll n){
	if(n%3==1){
		ll x=1;
		while(4*x<=n)x*=4;
		return x+(n-x)/3;
	}
	if(n%3==2){
		ll x=1;
		while(4*x<=n)x*=4;
		return 2*x+calc((n-(x+1))/3);
	}
	return solve(n-1)^solve(n-2);
}

int main() {
	int T;read(T);while(T--){
		ll n;read(n);
		printf("%lld\n",solve(n));
	}
	return 0;
}