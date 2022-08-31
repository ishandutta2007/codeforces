#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N = 510;
int n,m,k,r[N][N],d[N][N];

ll f[N][N][22];
inline ll dp(int l,int r,int k){
	if (k==0) return f[l][r][k]=0;
	if (~f[l][r][k]) return f[l][r][k];
	ll ret=1e18;
	if (l>1) ret=min(ret,dp(l-1,r,k-1)+2*d[l-1][r]);
	if (l<n) ret=min(ret,dp(l+1,r,k-1)+2*d[l][r]);
	if (r>1) ret=min(ret,dp(l,r-1,k-1)+2*::r[l][r-1]);
	if (r<m) ret=min(ret,dp(l,r+1,k-1)+2*::r[l][r]);
	return f[l][r][k]=ret;
}

int main(){
	n=read(),m=read(),k=read();
	For(i,1,n) FOR(j,1,m) r[i][j]=read();
	FOR(i,1,n) For(j,1,m) d[i][j]=read();
	if (k&1){
		For(i,1,n){
			For(j,1,m) printf("-1 ");
			puts("");
		}
		return 0;
	}
	fil(f,-1);
	For(i,1,n){
		For(j,1,m) printf("%lld ",dp(i,j,k/2));
		puts("");
	}
}