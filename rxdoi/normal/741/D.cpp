#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if ((y=E[i].y)!=fa)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=5e5+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,c,nxt;
} E[N];
Vi V[N];
int las[N],val[N],id[N],res[N],dep[N],sz[N],fa[N];
int mx[1<<22];
int n,cnt,x;
char ch[10];

void Add_Edge(int x,int y,int c){
	E[cnt]=(Edge){y,c,las[x]};las[x]=cnt++;
}
void Upd(int &x,int y){
	x=max(x,y);
}
void Merge(int &x,int y,int z){
	for (int i:V[x])
		for (int j=-1;j<22;j++){
			int tmp=(~j?1<<j:0)^val[i];
			Upd(res[z],dep[i]+mx[tmp]-2*dep[z]);
		}
	for (int i:V[x]){
		Upd(mx[val[i]],dep[i]);
		if (y) V[y].pb(i);
	}
	if (y) x=y;
}
void dfs(int x,int fa,int isson){
	int son=0;
	sz[x]=1;
	V[id[x]=x].pb(x);
	Rep(x){
		dep[y]=dep[x]+1;
		val[y]=val[x]^(1<<E[i].c);
		if (sz[y]>sz[son]) son=y;
	}
	Rep(x) if (y!=son) dfs(y,x,0);
	if (son) dfs(son,x,1);
	Merge(id[x],id[son],x);
	Rep(x) if (y!=son) Merge(id[y],id[x],x);
	if (!isson){
		for (int a:V[id[x]]) mx[val[a]]=-oo;
	}
}
void Dfs(int x,int fa){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			Dfs(y,x);
			res[x]=max(res[x],res[y]);
		}
}

int main(){
	For(i,0,1<<22) mx[i]=-oo;
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,2,n+1){
		fa[i]=IN();
		scanf("%s",ch);
		Add_Edge(fa[i],i,ch[0]-'a');
	}
	for (int i=n;i>1;i--){
		sz[i]++;
		sz[fa[i]]+=sz[i];
	}
	dfs(1,-1,0);
	Dfs(1,-1);
	For(i,1,n+1) printf("%d ",res[i]);
	puts("");
}