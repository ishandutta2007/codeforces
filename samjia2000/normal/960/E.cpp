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

const int N = 200005;
const int mo = 1e9+7;

int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int val[N];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int dep[N];
int f[N][2];
bool vis[N];

void dfs1(int x){
	vis[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!vis[e[p].x]){
		dep[e[p].x]=dep[x]+1;
		dfs1(e[p].x);
		f[x][0]+=f[e[p].x][0];
		f[x][1]+=f[e[p].x][1];
	}
	f[x][dep[x]&1]++;
}

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

LL ans;

void getans(int x){
	vis[x]=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (vis[e[p].x])getans(e[p].x);
	LL tmp=0;
	int d=dep[x]&1;
	for(int p=h[x];p;p=e[p].nxt)
	if (dep[e[p].x]==dep[x]+1){
		int y=e[p].x;
		tmp=add(tmp,1ll*f[y][d]*(n-f[y][0]-f[y][1])%mo);
		tmp=dec(tmp,1ll*f[y][d^1]*(n-f[y][0]-f[y][1])%mo);
	}
	tmp=add(tmp,n);
	if (x!=1){
		tmp=add(tmp,1ll*(f[1][d]-f[x][d])*(f[x][0]+f[x][1])%mo);
		tmp=dec(tmp,1ll*(f[1][d^1]-f[x][d^1])*(f[x][0]+f[x][1])%mo);
	}
	tmp=tmp*((val[x]%mo+mo)%mo)%mo;
	ans=add(ans,tmp);
}

int main(){
	n=get();
	fo(i,1,n)val[i]=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	dep[1]=1;
	dfs1(1);
	ans=0;
	getans(1);
	cout<<ans<<endl;
	return 0;
}