#include<bits/stdc++.h>

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

const int N = 5e5+5;
const int mo = 998244353;

LL mi[N];
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int n;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

bool vis[N];
LL ans;
int siz[N];
LL f[N][2],g[N][2];
int fa[N];

void dfs(int x){
	siz[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!siz[e[p].x]){
		fa[e[p].x]=x;
		dfs(e[p].x);
		siz[x]+=siz[e[p].x];
	}
	g[x][0]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x){
		int y=e[p].x;
		LL f0=f[x][0],f1=f[x][1],g0=g[x][0],g1=g[x][1];
		f[x][0]=f[x][1]=g[x][0]=g[x][1]=0;
		//cut
		f[x][0]=f0*mi[siz[y]-1]%mo;
		f[x][1]=f1*mi[siz[y]-1]%mo;
		g[x][0]=g0*mi[siz[y]-1]%mo;
		g[x][1]=g1*mi[siz[y]-1]%mo;
		//stay
		//00
		g[x][1]=(g[x][1]+g0*g[y][0])%mo;
		f[x][1]=(f[x][1]+g0*f[y][0]+f0*g[y][0])%mo;
		//01
		g[x][0]=(g[x][0]+g0*g[y][1])%mo;
		f[x][0]=(f[x][0]+g0*f[y][1]+f0*g[y][1]+g0*g[y][1])%mo;
		//10
		g[x][1]=(g[x][1]+g1*g[y][0])%mo;
		f[x][1]=(f[x][1]+g1*f[y][0]+f1*g[y][0])%mo;
		//11
		g[x][1]=(g[x][1]+g1*g[y][1])%mo;
		f[x][1]=(f[x][1]+g1*f[y][1]+f1*g[y][1]+g1*g[y][1])%mo;
	}
	if (x==1)ans=(ans+f[x][0]+f[x][1]+g[x][1])%mo;
	else ans=(ans+(f[x][0]+f[x][1]+g[x][1])%mo*mi[n-siz[x]-1])%mo;
}

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	mi[0]=1;
	fo(i,1,n)mi[i]=mi[i-1]*2%mo;
	dfs(1);
	ans=ans*2%mo;
	cout<<ans<<endl;
	return 0;
}