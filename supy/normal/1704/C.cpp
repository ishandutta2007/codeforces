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

const int N = 5e5+11;
int n,m,a[N],s[N];
int main() {
	int T;read(T);while(T--){
		read(n);read(m);
		rep(i,1,m)read(a[i]);
		sort(a+1,a+m+1);
		rep(i,1,m-1)s[i]=a[i+1]-a[i]-1;
		s[m]=n-(a[m]-a[1]+1);
		sort(s+1,s+m+1);
		int res=0;
		per(i,m,1){
			s[i]-=4*(m-i);
			res+=max(s[i]>=2?s[i]-1:s[i],0);
		}
		printf("%d\n",n-res);
	}
	return 0;
}