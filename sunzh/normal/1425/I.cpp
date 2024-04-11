#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc() {
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
	int x=0;
	char ch=getc();
	while(!isdigit(ch))ch=getc();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getc();
	return x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;int head[50010],nxt[50010],to[50010];
int depth[50010],dep[50010];
int lst[50010];
int a[50010];
int b[50010];
int dfn[50010];
int idx;
int siz[50010];
int tot;
inline void dfs(int x){
	dfn[x]=++idx;
	siz[x]=1;
	for(register int i=head[x];i;i=nxt[i]){
		depth[to[i]]=depth[x]+1;
		dfs(to[i]);
		siz[x]+=siz[to[i]];
	}
}
inline void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
int main(){
//	memset(lst,-0x3f,sizeof(lst));
	n=read(),q=read();
	for(register int i=1;i<=n;++i) b[i]=read();
	for(register int i=2;i<=n;++i){
		int _=read();add(_,i);
	}
	dfs(1);
	for(register int i=1;i<=n;++i) a[dfn[i]]=b[i],dep[dfn[i]]=depth[i];
	for(register int i=1;i<=q;++i){
		int x=read();
		int sum=0,cnt=0;
		int r=dfn[x]+siz[x]-1;
		for(register int j=dfn[x];j<=r;++j){
			if(lst[j]<=i){
				++cnt;sum+=dep[j];lst[j]=i+a[j];
			}
		}
		sum-=dep[dfn[x]]*cnt;
		printf("%d %d\n",sum,cnt);
//		print(sum);putchar(' ');print(cnt);putchar('\n');
	}
	return 0;
}