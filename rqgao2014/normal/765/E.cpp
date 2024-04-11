#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;

const int N=200005;
struct node{int to,next;}p[N<<2];
int head[N],tot,n,now[N],du[N];
bool vis[N],isok;
vector<pii> a;

void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
	p[++tot]=(node){x,head[y]};head[y]=tot;	
}
inline void del(int x,int fa){
	du[fa]--;vis[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||y==fa) continue;
		del(y,x);
	}
}
inline void dfs(int x,int fa){
	int son=0,id=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||y==fa) continue;
		dfs(y,x);
		if(~now[y]) son++,id=y; else son+=2;
	}
	if(!son){now[x]=1;return;}
	if(son==1){now[x]=(~now[id]?now[id]:-2)+1;return;}
	a.clear();
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||y==fa||now[y]==-1) continue;
		a.pb(mp(now[y],y));
	}
	sort(a.begin(),a.end());
	int m=a.size();
	for(int i=0;i<m;i++){
		int r=i;
		while(r<m&&a[r].FF==a[i].FF) r++;
		for(int j=i+1;j<r;j++) del(a[j].SS,x),isok=1;
		i=r-1;
	}
	now[x]=-1;
}
int check(){
	for(int i=1;i<=n;i++) if(du[i]>2) return i;
	return -1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);du[x]++;du[y]++;
	}
	while(1){
		int root=check();isok=0;
		if(root==-1) break;
		dfs(root,-1);
		if(!isok) break;
	}
	if(check()==-1){
		int ans=n-1;
		for(int i=1;i<=n;i++) ans-=vis[i];
		while(ans%2==0) ans/=2;
		printf("%d\n",ans);
	}
	else puts("-1");
	return 0;
}