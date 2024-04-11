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

ll p,q;
Vi calc(int n){
	Vi a;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		a.pb(i);while(n%i==0)n/=i;
	}
	if(n>1)a.pb(n);return a;
}
ll f(ll p, ll x){
	ll res=1;
	while(p%q==0)p/=x,res*=x;
	return res;
}
int main() {
	int T;read(T);while(T--){
		read(p);read(q);
		Vi a=calc(q);
		ll mn=1e18;for(int x:a)umin(mn,f(p,x));
		cout<<p/mn<<endl;
	}
	return 0;
}