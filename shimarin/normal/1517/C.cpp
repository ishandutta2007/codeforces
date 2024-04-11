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
const int dx[2] = {0,1};
const int dy[2] = {-1,0};
int n,a[N],vis[N][N];

int tot;
inline void dfs(pa u,int lim){
	if (tot==lim) return;
	For(k,0,1){
		int x=u.fi+dx[k],y=u.se+dy[k];
		if (x<=0||y<=0||x>n||y>n||vis[x][y]||tot==lim) continue;
		vis[x][y]=lim,++tot,dfs(mp(x,y),lim);
	}
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n){
		tot=1,vis[i][i]=a[i],dfs(mp(i,i),a[i]);
		if (tot<a[i]) return puts("-1"),0;
	}
	For(i,1,n){
		For(j,1,i) printf("%d ",vis[i][j]);
		puts("");
	}
}