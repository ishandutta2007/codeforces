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

const int N = 1005, mo = 998244353, mo2 = 1e9+9;
int n,m,f[N][N],g[N][N],sta[N],top,deg[N],s[N],len;
Vi e[N];
int main() {
	int T;read(T);while(T--){
		read(n);read(m);
		rep(i,0,n)rep(j,0,n)f[i][j]=g[i][j]=0;
		rep(i,1,n)deg[i]=0,e[i].clear();
		top=len=0;
		rep(i,1,n)read(f[i][0]),g[i][0]=f[i][0];
		rep(i,1,m){
			int x,y;read(x);read(y);
			e[x].pb(y);deg[y]++;
		}
		rep(i,1,n)if(!deg[i])sta[++top]=i;
		while(top){
			int u=sta[top--];s[++len]=u;
			for(int v:e[u]){
				if(!--deg[v])sta[++top]=v;
				rep(i,0,n-1)f[v][i+1]=(f[v][i+1]+f[u][i])%mo,g[v][i+1]=(g[v][i+1]+g[u][i])%mo2;
			}
		}
		int mx=n;while(mx>0&&!f[s[n]][mx]&&!g[s[n]][mx])mx--;
		rep(i,0,mx)if(f[s[n]][i]||g[s[n]][i]){
			f[s[n]][i+1]=(f[s[n]][i+1]+f[s[n]][i]-1)%mo;
			g[s[n]][i+1]=(g[s[n]][i+1]+g[s[n]][i]-1)%mo2;
		}
		printf("%d\n",(mx+f[s[n]][mx])%mo);
	}
	return 0;
}