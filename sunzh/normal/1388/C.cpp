#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n,m,tot;
int head[200010],nxt[400010],to[400010];
int p[100010],h[100010];
int siz[100010];
bool flag;
void dfs(int x,int fa){
	if(flag) return ;
	siz[x]=p[x];
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		dfs(v,x);
		if(flag) return ;
		sum+=h[v];
		siz[x]+=siz[v];
	}
	if(sum-p[x]>h[x]) flag=1;
	if(h[x]>siz[x]||h[x]<-siz[x]) flag=1;
	if((h[x]+siz[x])&1) flag=1;
}
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
int main(){
	T=read();
	while(T--){
		flag=0;
		n=read(),m=read();
		for(int i=1;i<=n;++i) p[i]=read();
		for(int i=1;i<=n;++i) h[i]=read();
		memset(head,0,sizeof(head));
		tot=0;
		for(int i=1;i<n;++i){
			int u=read(),v=read();add(u,v);add(v,u);
		}
		dfs(1,0);
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}