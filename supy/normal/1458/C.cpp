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

const int N = 1003;
int n,m,a[N][N],b[N][N],c[N][N],p[5],f[5];char s[666666];
int g(int x){x=x%n;return x<=0?x+n:x;}
int main() {
	int T;read(T);while(T--){
		read(n);read(m);
		rep(i,1,n)rep(j,1,n)read(a[i][j]);
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		rep(i,1,3)p[i]=i;
		scanf("%s",s+1);int len=strlen(s+1);
		rep(j,1,len){
			if(s[j]=='I')swap(p[2],p[3]),swap(f[2],f[3]);
			if(s[j]=='C')swap(p[1],p[3]),swap(f[1],f[3]);
			if(s[j]=='R')f[2]++;
			if(s[j]=='L')f[2]--;
			if(s[j]=='D')f[1]++;
			if(s[j]=='U')f[1]--;
		}
		//rep(i,1,3)printf("%d:%d %d\n",i,p[i],f[i]);
		rep(i,1,n)rep(j,1,n){
			int t[]={0,i,j,a[i][j]};
			b[g(t[p[1]]+f[1])][g(t[p[2]]+f[2])]=g(t[p[3]]+f[3]);
		}
		rep(i,1,n)rep(j,1,n)printf("%d%c",b[i][j],j<n?' ':'\n');
		puts("");
	}
	return 0;
}