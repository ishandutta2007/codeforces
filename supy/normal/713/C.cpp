#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3030;
const ll inf=1e18;
int n,a[N];ll f[N][N];
int s[N];
int Abs(int x){return x>0?x:-x;}
int main() {
	read(n);rep(i,1,n)read(a[i]),a[i]-=i;
	rep(i,1,n)s[i]=a[i];sort(s+1,s+n+1);
	rep(i,0,n)rep(j,0,n)f[i][j]=inf;
	f[0][1]=0;
	rep(i,1,n){
		ll v=inf;
		for(int j=1;j<=n;j++)umin(v,f[i-1][j]),umin(f[i][j],v+Abs(s[j]-a[i]));
	}
	ll res=inf;rep(i,1,n)umin(res,f[n][i]);
	cout<<res;
	return 0;
}