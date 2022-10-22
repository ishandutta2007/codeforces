#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int head[600010],nxt[2000010],to[2000010],id[2000010],tot=1;
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,id[tot]=z;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,id[tot]=-z;
}
bool used[2000010];
int ans[2000010];
int deg[600010];
// vector<PII>vec[600010];
void dfs(int x){
	for(int &i=head[x];i;i=nxt[i]){
		if(used[i]||used[i^1]) continue ;
		used[i]=1;ans[abs(id[i])]=(id[i]>0?1:2);dfs(to[i]);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		if(w==1){
			add(u,v,i);++deg[u],++deg[v];
		}
		else{
			add(u+n,v+n,i);++deg[u+n],++deg[v+n];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(deg[i]&1){++cnt;
			if(deg[i+n]&1){
				add(i,i+n,0);
			}
			else add(i,n+n+1,0);
		}
	}
	for(int i=1;i<=n;++i){
		if(~deg[i]&1){
			if(deg[i+n]&1) add(i+n,n+n+1,0);
		}
	}
	for(int i=1;i<=n+n+1;++i) dfs(i);
	printf("%d\n",cnt);
	for(int i=1;i<=m;++i) printf("%d",ans[i]);
}