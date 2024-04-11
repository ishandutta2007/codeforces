#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5+5;
int n,m,x[MAXN+5],y[MAXN+5],deg[MAXN+5];
vector<int> g[MAXN+5];bool vis[MAXN+5];
void dfs(int x){if(vis[x]) return;vis[x]=1;ffe(it,g[x]) dfs(*it);}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) deg[i]=vis[i]=0;
	for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]),deg[x[i]]++,deg[y[i]]++;
	for(int i=1;i<=n;i++) g[i].clear();
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(x[i]==y[i]){cnt--;continue;}
		g[x[i]].pb(y[i]),g[y[i]].pb(x[i]);
	}
	queue<int> q;for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=1;
		ffe(it,g[x]){
			deg[*it]--;
			if(deg[*it]==1) q.push(*it);
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]&&g[i].size()){cnt++;dfs(i);}
	printf("%d\n",m+cnt);
}
signed main(){
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}