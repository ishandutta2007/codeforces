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

const int N = 6e5+11;
int n,m,a[N],b[N],res=2e9,gs[N],v[N<<2];Pii s[N];int len;
void mdy(int p, int x){
	p=m+p+1;v[p]=x;p>>=1;
	while(p)v[p]=max(v[p<<1],v[p<<1|1]),p>>=1;
}
int main() {
	rep(i,1,6)read(a[i]);
	read(n);
	rep(i,1,n)read(b[i]);
	sort(a+1,a+7);sort(b+1,b+n+1);
	rep(i,1,6)rep(j,1,n)s[++len]=mp(b[j]-a[i],j);
	sort(s+1,s+len+1);
	for(m=1;m<=n+2;m<<=1);
	rep(i,1,n)mdy(i,b[i]-a[6]);
	rep(i,1,len){
		umin(res,v[1]-s[i].fi);
		gs[s[i].se]++;
		if(gs[s[i].se]>=6)break;
		mdy(s[i].se,b[s[i].se]-a[6-gs[s[i].se]]);
	}
	cout<<res;
	return 0;
}