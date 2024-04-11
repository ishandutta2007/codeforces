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

const int N = 200005;

int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

LL f[N][2],g[N][2];
bool vis[N];
LL ans;
int dep[N];

void dfs(int x){
	vis[x]=1;
	for(int p=h[x];p;p=e[p].nxt){
		int y=e[p].x;
		if (!vis[y]){
			dep[y]=dep[x]+1;
			dfs(y);
			LL f1=f[y][0],f0=f[y][1],g1=g[y][0],g0=g[y][1];
			//00
			ans=ans+f[x][0]*(g0-f0*dep[x])/2+f0*(g[x][0]-f[x][0]*dep[x])/2;
			//01
			ans=ans+(g[x][0]-f[x][0]*dep[x])/2*f1+f[x][0]*(g1-f1*(dep[x]-1))/2;
			//10
			ans=ans+(g[x][1]-f[x][1]*(dep[x]-1))/2*f0+f[x][1]*(g0-f0*dep[x])/2;
			//11
			ans=ans+(g[x][1]-f[x][1]*(dep[x]-1))/2*f1+f[x][1]*(g1-f1*(dep[x]+1))/2;
			f[x][0]=f[x][0]+f0;
			f[x][1]=f[x][1]+f1;
			g[x][0]=g[x][0]+g0;
			g[x][1]=g[x][1]+g1;
		}
	}
	ans=ans+(g[x][0]-f[x][0]*dep[x])/2+(g[x][1]-f[x][1]*(dep[x]-1))/2;
	f[x][0]=f[x][0]+1;
	g[x][0]=g[x][0]+dep[x];
}

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	ans=0;
	dep[1]=1;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}