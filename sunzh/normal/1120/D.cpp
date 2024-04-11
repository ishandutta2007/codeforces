#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int w[200010];
vector<int>vec[200010];
struct edge{
	int u,v,w,id;
	friend bool operator <(const edge &x,const edge &y){
		return x.w<y.w;
	}
}e[200010];
int cnt;
int idx;
void dfs(int x,int f){
	bool flag=0;
	int in=idx+1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs(v,x);flag=1;
	}
	if(!flag) ++idx;
	e[++cnt]=edge{in,idx+1,w[x],x};
}
int fa[200010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) w[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	dfs(1,1);
	sort(e+1,e+cnt+1);
	long long ans=0;
	int num=0;
	vector<int>opt;
	int pos=1;
	++idx;
	for(int i=1;i<=idx;++i) fa[i]=i;
	while(pos<=cnt){
		int r=pos;
		for(int i=pos+1;i<=cnt;++i){
			if(e[i].w==e[pos].w) r=i;
			else break ;
		}
		for(int i=pos;i<=r;++i){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx!=fy) opt.pb(e[i].id);
		}
		for(int i=pos;i<=r;++i){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx!=fy){
				ans+=e[i].w;
				++num;
				fa[fx]=fy;
				if(num+1==idx){
					break ;
				}
			}
		}
		if(num+1==idx) break ;
		pos=r+1;
	}
	sort(opt.begin(),opt.end());
	printf("%lld %d\n",ans,opt.size());
	for(int i:opt) printf("%d ",i);
}