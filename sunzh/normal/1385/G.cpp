#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[3][200010];
vector<PII>pos[200010],sat;
int fa[200010],siz[200010];
int tot;
bool vis[200010];
int head[500010],nxt[2000010],to[2000010];
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot;to[tot]=y;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
vector<int> tmp,ans;
bool used[200010];
void bfs(int x){
	queue<PII>q;
	q.push(mp(x,1));
	int s[2]={0,0};
	vector<int>st[2];
	vis[x]=1;s[1]=siz[x],st[1].pb(x);
	while(!q.empty()){
		PII u=q.front();
		q.pop();
		for(int i=head[u.fi];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue ;
			vis[v]=1;s[u.se^1]+=siz[v];st[u.se^1].pb(v);
			q.push(mp(v,u.se^1));
		}
	}
	if(s[0]<s[1]) for(int i:st[0]) tmp.pb(i);
	else for(int i:st[1]) tmp.pb(i);
}
int main(){
	T=read();
	while(T--){
//		printf("T:%d\n",T);
//		printf("-----------------");
		n=read();
		sat.clear();ans.clear();tmp.clear();
		tot=0;
		bool flag=0;
		for(int i=1;i<=n;++i){
			pos[i].clear();
			fa[i]=i,siz[i]=1;
			vis[i]=head[i]=used[i]=0;
		}
		for(int i=1;i<=2;++i) for(int j=1;j<=n;++j){
			a[i][j]=read();if(a[i][j]>n) flag=1;else pos[a[i][j]].pb(mp(i,j));
		}
		for(int i=1;i<=n;++i){
			if(pos[i].size()!=2){
				flag=1;break ;
			}
			PII a=pos[i][0],b=pos[i][1];
			if(a.fi==b.fi){
				sat.pb(mp(a.se,b.se));
			}
			else {
				int fx=find(a.se),fy=find(b.se);
				if(fx!=fy) fa[fx]=fy,siz[fy]+=siz[fx];
			}
		}
		if(flag){
			printf("-1\n");continue ;
		}
		for(auto i:sat){
			int fx=find(i.fi),fy=find(i.se);
			if(fx==fy){
				flag=1;break ;
			}
			else add(fx,fy),add(fy,fx);
		} 
		if(flag){
			printf("-1\n");
		}
		else {
			for(int i=1;i<=n;++i){
				if(fa[i]==i&&!vis[i]) bfs(i);
			}
			for(int i:tmp) used[i]=1;
			for(int i=1;i<=n;++i) if(used[find(i)]) ans.pb(i);
			printf("%d\n",ans.size());
			for(int i:ans) printf("%d ",i);
			putchar('\n');
		}
	}
}