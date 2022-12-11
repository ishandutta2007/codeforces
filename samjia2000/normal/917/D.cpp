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

const int N = 105;
const int mo = 1e9+7;

LL f[N][N][N],g[N][N];
int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
bool vis[N];
int siz[N];
LL c[N][N];

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}

void dfs(int x){
	vis[x]=siz[x]=f[x][0][1]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!vis[e[p].x]){
		int y=e[p].x;
		dfs(y);
		fo(i,0,siz[x])
			fo(j,0,siz[x]){
				g[i][j]=f[x][i][j];
				f[x][i][j]=0;
			}
		fo(i1,0,siz[x])
			fo(j1,0,siz[x])
			if (g[i1][j1])
				fo(i2,0,siz[y])
					fo(j2,0,siz[y])
					if (f[y][i2][j2]){
						//cut
						f[x][i1+i2+1][j1]=add(f[x][i1+i2+1][j1],g[i1][j1]*f[y][i2][j2]%mo*j2%mo);
						//connect
						f[x][i1+i2][j1+j2]=add(f[x][i1+i2][j1+j2],g[i1][j1]*f[y][i2][j2]%mo);
					}
		siz[x]+=siz[y];
	}
}

LL quickmi(LL x,LL tim){
	LL ans=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ans=ans*x%mo;
	return ans;
}

LL F[N],G[N];

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	dfs(1);
	c[0][0]=1;
	fo(i,1,n){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=add(c[i-1][j],c[i-1][j-1]);
	}
	fd(i,n,1){
		G[i]=0;
		fo(x,1,n)G[i]=add(G[i],f[1][i-1][x]*x%mo);
		if (i==1)G[i]=1;
		else G[i]=G[i]*quickmi(n,i-2)%mo;
		F[n-i]=G[i];
	}
	fd(i,n-1,0)fo(j,i+1,n-1)F[i]=(F[i]+mo-F[j]*c[j][i]%mo)%mo;
	fo(i,0,n-1)printf("%I64d ",F[i]);putchar('\n');
	return 0;
}