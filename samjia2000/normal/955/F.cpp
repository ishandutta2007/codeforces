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

const int N = 3e5+5;

int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int d[N],mx[N],st[N],len;
bool vis[N];
int se[N];

LL ans;
int f[N][20],g[N][20];
int fa[N];
int key[N],k;

void dfs(int x){
	vis[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!vis[e[p].x]){
		int y=e[p].x;
		fa[y]=x;
		dfs(y);
		d[x]=max(d[x],d[y]);
	}
	f[x][1]=g[x][1]=n;
	fo(i,2,18){
		k=0;
		for(int p=h[x];p;p=e[p].nxt)
			if (fa[e[p].x]==x){
				key[++k]=f[e[p].x][i-1];
				g[x][i]=max(g[x][i],g[e[p].x][i]);
			}
		sort(key+1,key+1+k);
		reverse(key+1,key+1+k);
		fo(j,1,k)if (key[j]>=j)f[x][i]=j;
		g[x][i]=max(g[x][i],f[x][i]);
	}
	d[x]++;
	LL ad=d[x];
	fo(i,1,18)ad+=max(0,g[x][i]-1);
	ans+=ad;
}

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}