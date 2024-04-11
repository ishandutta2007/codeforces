#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n;
int a[200010],b[200010];
int ans;
int f[200010],pos[200010];
int head[200010],nxt[200010],to[200010];
int tot,dfn,cnt;
int in[200010];
bool vis[200010];
void dfs(int x){
	if(vis[x]) return ;
	vis[x]=1;
	f[++dfn]=x;
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		dfs(v);
		if(a[v]<0){
			in[v]=0;
		}
		else sum+=a[v];
	}
	a[x]+=sum;
	ans+=a[x];
}
void print(int x){
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(in[v]){
			print(v);
		}
	}
	printf("%d ",x);
}
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		b[i]=read();if(b[i]!=-1) add(b[i],i),++in[i];
	}
	for(int i=1;i<=n;++i) if(!in[i]&&!vis[i]) dfs(i);
	printf("%lld\n",ans);
	for(int i=1;i<=dfn;++i) if(!in[f[i]]) print(f[i]);
	printf("\n");
}