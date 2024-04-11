#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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
 
const int N = 1010, mod = 998244353;
int n,a[N],m,dp[N][4],f[4][4],G[4];
vector<pa>e[N];
 
inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}
 
int cnt;
struct node{
	int a[65][65];
	inline node operator * (const node &p)const{
		node ret;
		For(i,0,cnt) For(j,0,cnt){
			ret.a[i][j]=0;
			For(k,0,cnt) ret.a[i][j]=(ret.a[i][j]+1ll*a[i][k]*p.a[k][j])%mod;
		}
		return ret;
	}
}t,pw[31];
 
int id[5][5][5];
bool vis[5];
inline void init(){
	cnt=-1;
	FOR(i,0,4) FOR(j,0,4) FOR(k,0,4) id[i][j][k]=++cnt;
	fil(t.a,0);
	FOR(i,0,4) FOR(j,0,4) FOR(k,0,4){
		FOR(p,0,3){
			fil(vis,0);
			FOR(q,0,3) if (f[p][q]){
				if (q==0) vis[i]=1;
				if (q==1) vis[j]=1;
				if (q==2) vis[k]=1;
			}
			int now=0;
			while (vis[now]) ++now;
			t.a[id[i][j][k]][id[now][i][j]]++;
		}
	}
	pw[1]=t;
	For(i,2,30) pw[i]=pw[i-1]*pw[i-1];
}
 
int g[65],nxt[65];
inline void Mul(int b){
	Dow(i,29,0) if (b&(1<<i)){
		For(j,0,cnt){
			For(k,0,cnt) nxt[k]=(nxt[k]+1ll*g[j]*pw[i+1].a[j][k])%mod;
		}
		For(j,0,cnt) g[j]=nxt[j],nxt[j]=0;
	} 
}
 
int main(){
	n=read();
	For(i,1,n) a[i]=read();
	m=read();
	For(i,1,m){
		int x=read(),y=a[x]-read()+1,z=read()-1;
		e[x].ep(y,z);
	}
	FOR(i,0,3) FOR(j,0,3) f[i][j]=read();
	init();
	dp[0][0]=1;
	For(i,1,n){
		sort(all(e[i])),reverse(all(e[i]));
		fil(g,0);
		g[id[3][3][3]]=1;
		int las=a[i]+1;
		for (auto j:e[i]){
			Mul(las-j.fi-1);
			FOR(x,0,4) FOR(y,0,4) FOR(z,0,4){
				fil(vis,0);
				FOR(q,0,3) if (f[j.se][q]){
					if (q==0) vis[x]=1;
					if (q==1) vis[y]=1;
					if (q==2) vis[z]=1;
				}
				int now=0;
				while (vis[now]) ++now;
				upd(nxt[id[now][x][y]],g[id[x][y][z]]);
			}
		//	printf("cao %d %d\n",las,j.fi);
		//	FOR(x,0,4) FOR(y,0,4) FOR(z,0,4) if (nxt[id[x][y][z]]){
		//		printf("%d %d %d %d\n",x,y,z,nxt[id[x][y][z]]);
		//	}
		//	puts("");
			For(k,0,cnt) g[k]=nxt[k],nxt[k]=0;
			las=j.fi;
		}
		Mul(las-1);
		fil(G,0);
		FOR(x,0,4) FOR(y,0,4) FOR(z,0,4) upd(G[x],g[id[x][y][z]]);
//		printf("%d\n",i);
//		FOR(j,0,4) printf("%d ",G[j]);puts("");
		FOR(j,0,4) FOR(k,0,4){
			dp[i][j^k]=(dp[i][j^k]+1ll*G[j]*dp[i-1][k])%mod;
		}
	}
	printf("%d\n",dp[n][0]);
}