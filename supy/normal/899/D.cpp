#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
ll n,ans,val,now;

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline ll calc(ll x) {
	if (n>=x) return x/2;
	return n-x/2;
}
int main() {
	read(n); if (n<=4) {printf("%lld\n",n*(n-1)/2); return 0;}
	val=9;
	while (1) {
		ll xx=val*10+9;
		if (xx>n+n-1) break;
		val=xx;
	}
	now=val;
	rep(i,0,9) {
		ans+=calc(now); now+=val+1;
		if (now>n+n-1) break;
	}
	cout<<ans;
	return 0;
}