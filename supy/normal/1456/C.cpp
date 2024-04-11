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

const int N = 1e6+11;
int n,k,a[N];ll res=-1e18,qz1[N],qz2[N],hz[N];
int main() {
	read(n);read(k);
	rep(i,1,n)read(a[i]);sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	if(!k){
		ll res=0,cur=0;
		rep(i,1,n)res+=cur,cur+=a[i];
		cout<<res;
		return 0;
	}
	rep(i,1,n)qz1[i]=qz1[i-1]+a[i],qz2[i]=qz2[i-1]+1ll*a[i]*i;
	per(i,n,1)hz[i]=hz[i+1]+(1ll*(n-i+1-1)/(k+1))*a[i];
	rep(i,1,n)if(1ll*i*(k+1)>=n){
		int c=(n-i)/k;assert(c<=i);
		umax(res,hz[i-c+1]+1ll*i*qz1[i-c]-qz2[i-c]);
	}
	cout<<res;
	return 0;
}