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
const int N = 1510;
int n,m,a[N][N],b[N][N],vis[N];
bitset<N>g[N],B;
poly ans;

inline void init(){
	For(i,1,n) For(j,1,m) if ((i==n)||(b[i][j]>b[i+1][j])) g[j][i]=1;
//	For(j,1,m){
//		For(i,1,n) printf("%d ",(int)g[j][i]);
//		puts("");
//	}
}

inline void work(){
	B[n]=1;
	while (233){
		int p=0;
		For(i,1,m) if (!vis[i]&&(B&g[i])==g[i]){p=i;break;}
		if (!p) break;
		ans.pb(p),vis[p]=1;
		FOR(i,1,n) if (b[i][p]<b[i+1][p]) B[i]=1;
	}
}

int ha[N],hb[N];
const int mod = 1e9+9, mod2 = 998244853;
const int base = 19260817, base2 = 1145141;
inline int Hash(int *a){
	int x=0,y=0;
	For(i,1,m){
		x=(1ll*x*base+a[i])%mod;
		y=(1ll*y*base2+a[i])%mod2;
	}
	return x^y;
}
int p[N];
map<int,poly>f;
map<int,int>l;
inline bool check(){
	For(i,1,n) ha[i]=Hash(a[i]),hb[i]=Hash(b[i]);
	For(i,1,n) f[ha[i]].pb(i);
	For(i,1,n){
		if (l[hb[i]]==siz(f[hb[i]])) return 0;
		p[i]=f[hb[i]][l[hb[i]]],++l[hb[i]];
	//	printf("  %d %d\n",i,p[i]);
	}
	//printf("  %d\n",(int)B[0]);
	FOR(i,1,n) if (!B[i]&&p[i]>p[i+1]) return 0;
	return 1;
}

int main(){
	n=read(),m=read();
	For(i,1,n) For(j,1,m) a[i][j]=read();
	For(i,1,n) For(j,1,m) b[i][j]=read();
	init(),work();
	if (!check()) return puts("-1"),0;
	reverse(all(ans));
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d ",i);
}