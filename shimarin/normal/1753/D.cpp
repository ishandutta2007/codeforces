#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
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

const int N = 3e5+10;
const int dx[4] = {0,0,-2,2};
const int dy[4] = {-2,2,0,0};
int n,m,p,q;
vector<char>a[N];
char s[N];
ll dis[N][2],fm[N][2];
bool vis[N][2];
struct node{
	ll d;
	int x,y;
	inline bool operator < (const node &p)const{
		return d>p.d;
	}
};

inline int id(int x,int y){
	return (x-1)*m+y;
}

vector<pa>e[N];
inline void Add(int x,int y,int z){
	e[y].ep(x,z);
}

int main(){
	n=read(),m=read();
	p=read(),q=read();
	For(i,0,n+1) a[i].resize(m+2);
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m) a[i][j]=s[j];
	}
	For(i,1,n){
		For(j,1,m) if (a[i][j]!='#'){
			if (a[i][j]=='D'){
				int x=i-1,y=j-1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i-1,y=j+1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i-2,y=j;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),q);
				}
			}
			if (a[i][j]=='L'){
				int x=i-1,y=j+1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i+1,y=j+1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i,y=j+2;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),q);
				}
			}
			if (a[i][j]=='R'){
				int x=i+1,y=j-1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i-1,y=j-1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i,y=j-2;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),q);
				}
			}
			if (a[i][j]=='U'){
				int x=i+1,y=j+1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i+1,y=j-1;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),p);
				}
				x=i+2,y=j;
				if (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#'){
					Add(id(i,j),id(x,y),q);
				}
			}
		}
	}
	priority_queue<node>q;
	For(i,1,n*m) For(j,0,1) dis[i][j]=1e18;
	For(i,1,n) For(j,1,m) if (a[i][j]=='.'){
		dis[id(i,j)][0]=0,fm[id(i,j)][0]=id(i,j);
		q.push((node){0,id(i,j),0});
	}
	while (!q.empty()){
		int u=q.top().x,f=q.top().y;q.pop();
		if (vis[u][f]) continue;
		vis[u][f]=1;
		for (auto [v,w]:e[u]){
			ll t=dis[u][f]+w;
			if (t<dis[v][0]){
				if (fm[v][0]!=fm[u][f]){
					dis[v][1]=dis[v][0],fm[v][1]=fm[v][0];
					q.push((node){dis[v][1],v,1});		
				}
				dis[v][0]=t,fm[v][0]=fm[u][f];
				q.push((node){dis[v][0],v,0});
			} else if (t<dis[v][1]&&fm[u][f]!=fm[v][0]){
				dis[v][1]=t,fm[v][1]=fm[u][f];
				q.push((node){dis[v][1],v,1});
			}
		}
	}
	ll ans=1e18;
	For(i,1,n) For(j,1,m){
		if (a[i][j]!='#'&&a[i][j+1]!='#'&&j+1<=m){
			int u=id(i,j),v=id(i,j+1);
			For(x,0,1) For(y,0,1) if (fm[u][x]!=fm[v][y]){
				ans=min(ans,dis[u][x]+dis[v][y]);
			}
		}
		if (a[i][j]!='#'&&a[i+1][j]!='#'&&i+1<=n){
			int u=id(i,j),v=id(i+1,j);
			For(x,0,1) For(y,0,1) if (fm[u][x]!=fm[v][y]){
				ans=min(ans,dis[u][x]+dis[v][y]);
			}
		}
	}
	if (ans==1e18) return puts("-1"),0;
	printf("%lld\n",ans);
}