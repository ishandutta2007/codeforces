#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
int T;
int n;
char s[300010];
int head[300010],nxt[600010],to[600010];
int tot;
int dfn[300010],low[300010];
int stk[300010];
int idx,siz;
bool vis[300010];
int ans;
void tarjan(int x){
	stk[++siz]=x;
	dfn[x]=low[x]=++idx;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		int t=stk[siz];
		int sz=1;
		while(t!=x){
			++sz;
			vis[t]=0;
			t=stk[--siz];
		}vis[x]=0;
		--siz;
		if(sz>1) ans+=sz;
	}
}
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s);
		tot=idx=siz=ans=0;
		for(int i=0;i<n;++i) dfn[i]=head[i]=vis[i]=0;
		for(int i=0;i<n;++i){
			if(s[i]=='-') add(i,(i+1)%n),add((i+1)%n,i);
			else if(s[i]=='>') add(i,(i+1)%n);
			else add((i+1)%n,i);
		}
		for(int i=0;i<n;++i){
			if(!dfn[i]) tarjan(i);
		}
		printf("%d\n",ans);
	}
}