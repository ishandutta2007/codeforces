#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<queue>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,tot;
int head[100010],nxt[200010],to[200010],len[200010];
int f[100010];
struct node{
	int val,pos;
}d[100010];
namespace dia{
	bool vis[100010];
	int dis1[100010],dis2[100010],tmp[100010];
	int spfa(int s,int d[]){
		queue<int>q;
		int now=0;
		int maxn=0;
		d[s]=0;
		while(!q.empty()) q.pop();
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(d[u]>maxn) now=u,maxn=d[u];
			vis[u]=0;
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(d[u]+len[i]<d[v]){
					d[v]=d[u]+len[i];
					if(!vis[v]){
						q.push(v);
						vis[v]=1;
					}
				}
			}
		}
		return now;
	}
	void solve(){
		memset(tmp,0x3f,sizeof(tmp));
		memset(dis1,0x3f,sizeof(dis1));
		memset(dis2,0x3f,sizeof(dis2));
		int a=spfa(1,tmp);
		int b=spfa(a,dis1);
		spfa(b,dis2);
		for(int i=1;i<=n;++i) f[i]=max(dis1[i],dis2[i]); 
	}
}
unordered_map<int,int>mp;
int fa[100010],fad[100010],siz[100010];
void dfs(int x,int fath){
	fad[x]=fath;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fath) continue ;
		dfs(v,x);
	}
}
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,len[tot]=z;
}
bool cmp(node x,node y){
	return x.val<y.val;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy,siz[fy]+=siz[fx];
} 
signed main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	dia::solve();
	for(int i=1;i<=n;++i) d[i].val=f[i],d[i].pos=i;
	sort(d+1,d+n+1,cmp);
	dfs(d[1].pos,0);
	int q=read();
	while(q--){
		int x=read();
		for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
		int t=n,ans=0;
		for(int i=n;i;--i){
			while(d[t].val-d[i].val>x){
				--siz[find(d[t].pos)];--t;
			}
			ans=max(ans,siz[find(d[i].pos)]);
			merge(d[i].pos,fad[d[i].pos]);
		}
		printf("%d\n",ans);
	}
	return 0;
}