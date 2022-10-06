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
int n,m;ll a[N];
map<ll,int>Map;
int main() {
	int T;read(T);while(T--){
		read(n);read(m);ll x;
		Map.clear();
		rep(i,1,n){
			a[i]=0;
			rep(j,1,m)read(x),a[i]+=j*x;
			Map[a[i]]++;
		}
		x=0;for(auto t:Map)if(t.se==n-1)x=t.fi;
		rep(i,1,n)if(Map[a[i]]==1){
			printf("%d %lld\n",i,a[i]-x);
			break;
		}
		// printf("qwq %d\n",SZ(Map));
		// rep(i,1,n)printf("%lld ",a[i]);puts("--- qwwq");
	}
	return 0;
}