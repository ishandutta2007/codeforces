#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;

ll n,l,r;
int ans;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
ll f(ll n) {
	if (n<=1) return 1;
	if (n<=3) return 3;
	return f(n/2)*2+1;
}
void solve(ll n, ll base) {
	if (n<=1) {if (l<=base+1&&r>=base+1) ans+=n; return;}
	ll g=f(n/2),mid=base+g+1;
	if (r<=mid) {
		if (r==mid) {ans+=(n&1);} //careful
		solve(n/2,base);
	}
	else if (l>=mid) {
		if (l==mid) {ans+=(n&1);}
		solve(n/2,mid);
	}
	else {
		ans+=(n&1);
		solve(n/2,base); solve(n/2,mid);
	}
}
int main() {
//	ll tmp=f((ll)(1<<25)<<25);
//	printf("%lld\n",tmp);
	read(n);read(l);read(r);
	solve(n,0);
	printf("%d",ans);
	return 0;
}