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

const int N = 166;
int lim,mo,f[N];
int calc(int d){
	if(lim>=(1<<d+1)-1)return 1<<d;
	return lim-(1<<d)+1;
}
int main() {
	int t;read(t);while(t--){
		read(lim);read(mo);memset(f,0,sizeof(f));
		int mx=0;while(lim>=(1<<mx+1))mx++;
		rep(i,0,mx)f[i]=calc(i);
		rep(i,0,mx)rep(j,i+1,mx)f[j]=(f[j]+1ll*f[i]*calc(j))%mo;
		int res=0;rep(i,0,mx)res=(res+f[i])%mo;
		printf("%d\n",res);
	}
	return 0;
}