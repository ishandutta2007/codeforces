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
#define se second
#define fi first

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

const int N = 300005;

int n,m;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int lef[N];
bool vis[N];
int fa[N],dep[N];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

void update(int x,int y){
	int mx=max(x,y),mi=min(x,y);
	while(x!=y){
		if (dep[x]>dep[y]){
			x=fa[x];
			mx=max(mx,x);
			mi=min(mi,x);
		}
		else{
			y=fa[y];
			mx=max(mx,y);
			mi=min(mi,y);
		}
	}
	lef[mx]=mi+1;
}

void dfs(int x){
	vis[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (e[p].x!=fa[x]){
		if (!vis[e[p].x]){
			dep[e[p].x]=dep[x]+1;
			fa[e[p].x]=x;
			dfs(e[p].x);
		}
		else update(x,e[p].x);
	}
}

LL pre[N];

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	fo(i,1,n)
	if (!vis[i]){
		dep[i]=1;
		dfs(i);
	}
	lef[0]=1;
	fo(i,1,n)lef[i]=max(lef[i],lef[i-1]);
	fo(i,1,n)pre[i]=pre[i-1]+lef[i];
	int q=get();
	fo(i,1,q){
		int l=get(),r=get();
		int L=l,R=r,w;
		while(L<=R){
			int mid=(L+R)/2;
			if (lef[mid]<=l)w=mid,L=mid+1;
			else R=mid-1;
		}
		LL ans=1ll*(l+w)*(w-l+1)/2-1ll*(l-1)*(w-l+1);
		if (w<r){
			w++;
			ans=ans+1ll*(w+r)*(r-w+1)/2-(pre[r]-pre[w-1])+r-w+1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}