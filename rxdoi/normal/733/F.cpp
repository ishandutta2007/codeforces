#include<set>
#include<map>
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

const int N=2e5+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,w,id,nxt;
} E[N*2];

struct edge{
	int x,y,w,c,id;
	bool operator < (const edge &B) const {return w<B.w;}
} e[N];
int las[N],pa[N];
int fa[20][N],mx[20][N],dep[N],w[N];
int n,m,cnt,S,pos,fnd,val;
ll sum,res=1ll<<60;

int Max(int a,int b){
	return w[a]>w[b]?a:b;
}
void Link(int x,int y,int w,int id){
	E[cnt]=(Edge){y,w,id,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,w,id,las[y]};las[y]=cnt++;
}
int getf(int x){
	return pa[x]==x?x:pa[x]=getf(pa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) pa[x]=y;
}
void dfs(int x){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[0][x]){
			fa[0][y]=x;
			dep[y]=dep[x]+1;
			mx[0][y]=E[i].id;
			dfs(y);
		}
}
void work(int x){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[0][x]){
			if (E[i].id!=val) printf("%d %d\n",E[i].id,E[i].w);
			work(y);
		}
}
int calc(int x,int y){
	int tmp=0;
	if (dep[x]>dep[y]) swap(x,y);
	for (int t=dep[y]-dep[x],i=0;i<20;i++) if (t>>i&1) tmp=Max(tmp,mx[i][y]),y=fa[i][y];
	if (x==y) return tmp;
	for (int i=19;~i;i--)
		if (fa[i][x]!=fa[i][y]){
			tmp=Max(tmp,mx[i][x]);
			tmp=Max(tmp,mx[i][y]);
			x=fa[i][x];y=fa[i][y];
		}
	tmp=Max(tmp,mx[0][x]);
	tmp=Max(tmp,mx[0][y]);
	return tmp;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,m+1) w[i]=e[i].w=IN();
	For(i,1,m+1) e[i].c=IN();
	For(i,1,m+1) e[i].x=IN(),e[i].y=IN(),e[i].id=i;
	S=IN();
	For(i,1,n+1) pa[i]=i;
	sort(e+1,e+m+1);
	For(i,1,m+1){
		int x=getf(e[i].x),y=getf(e[i].y);
		if (x!=y){
			pa[x]=y;
			sum+=e[i].w;
			Link(e[i].x,e[i].y,e[i].w,e[i].id);
		}
	}
	dfs(1);
	For(t,1,20){
		For(i,1,n+1){
			fa[t][i]=fa[t-1][fa[t-1][i]];
			mx[t][i]=Max(mx[t-1][i],mx[t-1][fa[t-1][i]]);
		}
	}
	For(i,1,m+1){
		ll tmp=sum-w[calc(e[i].x,e[i].y)]+e[i].w-S/e[i].c;
		if (tmp<res) res=tmp,pos=i;
	}
	cout<<res<<endl;
	val=calc(e[pos].x,e[pos].y);
	work(1);
	printf("%d %d\n",e[pos].id,e[pos].w-S/e[pos].c);
}