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

const int N = 610;
const ll inf = 1e15;
int n,m,q;
ll f[N][N],e[N][N],l[N][N],mx[N][N];
bool vis[N][N];

int main(){
	n=read(),m=read();
	For(i,1,n) For(j,1,n) f[i][j]=inf;
	For(i,1,n) f[i][i]=0;
	For(i,1,m){
		int x=read(),y=read(),z=read();
		f[x][y]=f[y][x]=z,e[x][y]=e[y][x]=z;
	}
	For(k,1,n) For(i,1,n) For(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	//For(i,1,n) For(j,i+1,n) printf("  %d %d %lld\n",i,j,f[i][j]);
	q=read();
	For(i,1,q){
		int x=read(),y=read(),z=read();
		l[x][y]=l[y][x]=z;
	}
	For(i,1,n) For(j,1,n) mx[i][j]=-inf;
	For(u,1,n) For(y,1,n) For(v,1,n) mx[u][y]=max(mx[u][y],l[u][v]-f[y][v]);
	For(u,1,n) For(x,1,n) For(y,1,n) if (e[x][y]&&f[u][x]+e[x][y]<=mx[u][y]) vis[x][y]=1;
	int ans=0;
	For(i,1,n) For(j,i+1,n) ans+=vis[i][j]|vis[j][i];
	printf("%d\n",ans);
}