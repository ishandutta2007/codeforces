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
#define pow powl
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
int n,m,Q;
struct edge{
	int u,v;
}e[200010];
int val[400010];
int R[200010];
set<int>st;
bool vis[200010];
int sum[400010],minn[400010];
bool tag[400010];
int fa[400010],son[400010][2];
void pushup(int p){
	sum[p]=sum[son[p][0]]+sum[son[p][1]]+(p<=n);
	if(val[minn[son[p][0]]]<val[minn[son[p][1]]]){
		minn[p]=minn[son[p][0]];
	}
	else minn[p]=minn[son[p][1]];
	if(val[p]<val[minn[p]]) minn[p]=p;
}
void pushdown(int x) {
	if(tag[x]){
		tag[x]=0;
		tag[son[x][0]]^=1;
		tag[son[x][1]]^=1;
		swap(son[x][0],son[x][1]);
	}
}
void rotate(int x){
	int y=fa[x],z=fa[y];
//	printf("rtt x:%d,y:%d,z:%d\n",x,y,z);
	if(son[y][0]==x){
		fa[y]=x,fa[son[x][1]]=y;
		son[y][0]=son[x][1];son[x][1]=y;
	}
	else {
		son[y][1]=son[x][0];
		fa[son[x][0]]=y;
		son[x][0]=y;
		fa[y]=x;
	}
	fa[x]=z;
//	printf("fa[x]:%d\n",fa[x]);
	if(z){
		if(son[z][0]==y) son[z][0]=x;
		else if(son[z][1]==y)son[z][1]=x;
	}
	pushup(y);pushup(x);
}
bool isson(int x){
	return (fa[x]!=0&&(son[fa[x]][0]==x||son[fa[x]][1]==x));
}
void dfs(int x){
	if(isson(x)) dfs(fa[x]);
	pushdown(x);
}
void splay(int x){
//	printf("x:%d\n",x);
	dfs(x);
	while(isson(x)){
		int y=fa[x],z=fa[y];
		if(isson(y)) rotate(((son[z][0]==y)^(son[y][0]==x))?x:y);
		rotate(x);
	}
}
void access(int x){
	int y=0;
	while(x){
		splay(x);son[x][1]=y;pushup(x);x=fa[y=x];
	}
}

void makeroot(int x){
//	printf("makert:x:%d\n",x);
	access(x);splay(x);tag[x]^=1;pushdown(x);
}

void split(int x,int y){
//	printf("split:x:%d,y:%d\n",x,y);
	makeroot(x);access(y);splay(y);
}
int findrt(int x){
//	printf("find:x:%d\n",x);
	access(x);splay(x);
	pushdown(x);
	while(son[x][0]) pushdown(x=son[x][0]);
	splay(x);
	return x;
}
void link(int x,int y){
//	printf("lk:x:%d,y:%d\n",x,y);
	makeroot(x);
	if(findrt(y)!=x) fa[x]=y;
}
void cut(int x,int y){
//	printf("ct:x:%d,y:%d\n",x,y);
	makeroot(x);
	if(findrt(y)==x&&fa[y]==x&&son[y][0]==0){
		fa[y]=son[x][1]=0;pushup(x);
	}
}
int main(){
	n=read(),m=read(),Q=read();
	memset(val,0x4f,sizeof(val));
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),val[n+i]=i;
	}
	for(int i=1;i<=n;++i) val[i]=0x3f7f7f7f;
	for(int i=m;i>=1;--i){
//		printf("i:%d\n",i);
		if(findrt(e[i].u)==findrt(e[i].v)){
			split(e[i].u,e[i].v);
			if(sum[e[i].v]&1){
//				printf("i:%d\n",i);
				st.insert(i);
			}
		}
		else {
//			printf("i:%d\n",i);
			link(e[i].u,i+n);link(i+n,e[i].v);
			vis[i]=1;
		}
	}
	int pr=0;
	memset(R,0x3f,sizeof(R));
	for(int i=1;i<=m;++i){
//		printf("I:%d      --------------\n",i);
		while(pr<i||(pr<m&&st.size())){
//			printf("i:%d,pr:%d\n",i,pr);
			++pr;
			if(!vis[pr]){
				st.erase(pr);
			}
			else{
				cut(e[pr].u,pr+n);cut(e[pr].v,pr+n);vis[pr]=0;
			}
		}
		if(st.empty()) R[i]=pr;else break ;
//		printf("R[%d]=%d\n",i,R[i]);
		val[i+n]=0x3f3f3f3f;
		if(findrt(e[i].u)!=findrt(e[i].v)){
			link(e[i].u,i+n),link(e[i].v,i+n);vis[i]=1;
		}
		else{
			split(e[i].u,e[i].v);
//			printf("sum:%d\n",sum[e[i].v]);
			int mn=minn[e[i].v];
			if(sum[e[i].v]&1){
				st.insert(mn-n);
			}vis[mn-n]=0;vis[i]=1;
//			printf("mn:%d\n",mn);
			cut(e[mn-n].u,mn);cut(e[mn-n].v,mn);
//			printf("i:%d\n",i);
			link(e[i].u,i+n);link(e[i].v,i+n);
		}
//		printf("i:%d\n",i);
	}
	for(int i=1;i<=Q;++i){
		int l=read(),r=read();
		if(r<R[l]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}