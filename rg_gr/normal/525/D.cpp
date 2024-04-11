// Problem: CF525D Arthur and Walls
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF525D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}

inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int n=read(),m=read();
char s[2021][2021];
void dfs(int x,int y)
{
	if(x==0||y==0||x>n||y>m||s[x][y]=='.')return;
	int dx=1,dy=1,f=0;
	dx=dy=1;
	if(s[x+dx][y+dy]=='.'&&s[x+dx][y]=='.'&&s[x][y+dy]=='.')f=1;
	dx=1,dy=-1;
	if(s[x+dx][y+dy]=='.'&&s[x+dx][y]=='.'&&s[x][y+dy]=='.')f=1;
	dx=-1,dy=1;
	if(s[x+dx][y+dy]=='.'&&s[x+dx][y]=='.'&&s[x][y+dy]=='.')f=1;
	dx=dy=-1;
	if(s[x+dx][y+dy]=='.'&&s[x+dx][y]=='.'&&s[x][y+dy]=='.')f=1;
	if(f==0)return;
	s[x][y]='.';
	dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
	dfs(x,y-1);dfs(x,y+1);
}
signed main()
{
	rg(n)scanf("%s",s[i]+1);gr
	rg(n)rg_(j,m)if(s[i][j]=='*')dfs(i,j);gr gr
	rg(n)printf("%s\n",s[i]+1);gr
	return 0;
}