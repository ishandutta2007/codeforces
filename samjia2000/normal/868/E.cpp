#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 55;
const int INF = 1e9;

int f[N][N];
struct edge{
	int x,l,nxt;
}e[N*2];
int h[N],tot;
int n;
int st;
int m;
int cri[N];
int dis[N][N];

void inse(int x,int y,int l){e[++tot].x=y;e[tot].l=l;e[tot].nxt=h[x];h[x]=tot;}

int d[N];
int g[N];

int be[N];

void dfs(int x,int v){
	be[x]=v;
	for(int p=h[x];p;p=e[p].nxt)
	if (!be[e[p].x])dfs(e[p].x,v);
}

int cnt[N];

int main(){
	n=get();
	fo(i,1,n)fo(j,1,n)if (i!=j)dis[i][j]=1e9;
	fo(i,2,n){
		int x=get(),y=get(),l=get();
		inse(x,y,l);
		inse(y,x,l);
		dis[x][y]=dis[y][x]=l;
		d[x]++,d[y]++;
	}
	st=get();
	fo(k,1,n)
		fo(i,1,n)
			fo(j,1,n)
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	m=get();
	fo(i,1,m)cnt[cri[i]=get()]++;
	fo(i,1,n)fo(j,1,m)f[i][j]=1e9;
	fo(c,1,m)
		fo(x,1,n)
		if (d[x]==1){
			fo(u,1,m)g[u]=-1e9;
			g[0]=INF;
			fo(y,1,n)
			if (d[y]==1&&y!=x){
				fd(u,m,1)
					fo(d,1,min(u,c))
					if (g[u-d]!=-INF)g[u]=max(g[u],min(g[u-d],f[y][c-d]+dis[x][y]));
			}
			f[x][c]=g[c];
		}
	be[st]=st;
	for(int p=h[st];p;p=e[p].nxt)dfs(e[p].x,e[p].x);
	int ans=INF;
	for(int p=h[st];p;p=e[p].nxt){
		int now=e[p].x,ct=0;
		fo(x,1,n)if(be[x]==now)ct+=cnt[x];
		fo(u,1,m)g[u]=-INF;
		g[0]=INF;
		fo(x,1,n)
		if (be[x]==now&&d[x]==1){
			fd(u,m,1)
				fo(d,1,u)
				if (g[u-d]!=-INF)g[u]=max(g[u],min(g[u-d],f[x][m-d]+dis[st][x]));
		}
		ans=min(ans,g[ct]);
	}
	cout<<ans<<endl;
	return 0;
}