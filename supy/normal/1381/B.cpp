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

const int N = 4040;
int n,a[N],b[N],len;
int f[N][N];
int main() {
	int T;read(T);while(T--){
		read(n);rep(i,1,2*n)read(a[i]);int mx=0;len=0;
		rep(i,1,2*n)if(a[i]>mx){
			b[++len]=i;mx=a[i];
		}
		b[++len]=2*n+1;
	//	rep(i,1,len-1)cerr<<b[i+1]-b[i]<<' ';cerr<<endl;
		rep(i,0,2*n)rep(j,0,2*n)f[i][j]=0;
		f[len][0]=1;
		per(i,len-1,1)rep(j,0,n){
			if(f[i+1][j])f[i][j+b[i+1]-b[i]]=1;//j+b[i+1]-b[i];
			if(f[i+1][j])f[i][j]=1;//j;
		}
		if(!f[1][n]){puts("NO");continue;}
		puts("YES");
	}
	return 0;
}