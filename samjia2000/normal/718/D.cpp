#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long long LL;
typedef unsigned long long ull;

const int N = 100010;
const int P = 543577;

int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int r[N];
ull f[N],g[N];
int fa[N];
bool vis[N];
set<ull>s;
int lef[N],rig[N];
ull a[N];
int k;
int siz[N];

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

void calcf(int x){
	vis[x]=1;
	siz[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!vis[e[p].x]){
		fa[e[p].x]=x;
		calcf(e[p].x);
		siz[x]+=siz[e[p].x];
		rig[e[p].x]=lef[x];
		lef[x]=e[p].x;
	}
	k=0;
	for(int y=lef[x];y;y=rig[y])a[++k]=f[y];
	sort(a+1,a+1+k);
	f[x]=0;
	fo(i,1,k)f[x]=f[x]*P+a[i]+1;
	f[x]=f[x]*P+siz[x];
}

void calcg(int x){
	for(int y=lef[x];y;y=rig[y]){
		k=0;
		if (x>1)a[k=1]=g[x];
		for(int u=lef[x];u;u=rig[u])
		if (u!=y)a[++k]=f[u];
		sort(a+1,a+1+k);
		g[y]=0;
		fo(i,1,k)g[y]=g[y]*P+a[i]+1;
		g[y]=g[y]*P+n-siz[y];
		calcg(y);
	}
}

void calc(){
	int ans=0;
	s.clear();
	fo(x,1,n){
		if (r[x]>=4)continue;
		a[k=1]=1;
		if (x>1)a[++k]=g[x];
		for(int y=lef[x];y;y=rig[y])a[++k]=f[y];
		sort(a+1,a+1+k);
		LL val=0;
		fo(i,1,k)val=val*P+a[i]+1;
		val=val*P+n+1;
		if (s.find(val)==s.end()){
			ans++;
			s.insert(val);
		}
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&n);
	fo(i,2,n){
		int x,y;
		scanf("%d%d",&x,&y);
		inse(x,y);
		inse(y,x);
		r[x]++,r[y]++;
	}
	calcf(1);
	g[1]=0;
	calcg(1);
	calc();
	return 0;
}