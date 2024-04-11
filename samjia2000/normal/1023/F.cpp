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

const int N = 1e6+5;
const int L = 21;
const int INF = 2e9;

int n,k,m;
struct EDGE{
	int x,y,v;
}g[N],f[N];
struct edge{
	int x,v,id,nxt;
}e[N];
int h[N],tot;
int Fa[N];

int getfather(int x){return Fa[x]==x?x:Fa[x]=getfather(Fa[x]);}

bool used[N];

void inse(int x,int y,int id){e[++tot].x=y;e[tot].id=id;e[tot].nxt=h[x];h[x]=tot;}

int fa[N][L];
int dep[N];
db tim;
int co[N];
int que[N],u;

void dfs(int x){
	que[++u]=x;
	fo(i,1,tim)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int p=h[x];p;p=e[p].nxt)
	if (!dep[e[p].x]){
		dep[e[p].x]=dep[x]+1;
		fa[e[p].x][0]=x;
		co[e[p].x]=e[p].id;
		dfs(e[p].x);
	}
}

int ans[N];

int val[N][L];

int lca(int x,int y){
	if (dep[x]<dep[y])swap(x,y);
	fd(i,tim,0)
	if (dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if (x==y)return x;
	fd(i,tim,0)
	if (fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

void add(int x,int l,int v){
	fd(i,tim,0)
	if ((l&(1<<i))>0){
		val[x][i]=min(val[x][i],v);
		x=fa[x][i];
	}
}

int main(){
	n=get();k=get();m=get();
	fo(i,1,k){
		g[i].x=get();g[i].y=get();
	}
	fo(i,1,m){
		f[i].x=get(),f[i].y=get(),f[i].v=get();
	}
	fo(i,1,n)Fa[i]=i;
	fo(i,1,k){
		int x=g[i].x,y=g[i].y;
		int fx=getfather(x),fy=getfather(y);
		Fa[fx]=fy;
		inse(x,y,-i),inse(y,x,-i);
	}
	fo(i,1,m){
		int x=f[i].x,y=f[i].y;
		int fx=getfather(x),fy=getfather(y);
		if (fx==fy)continue;
		used[i]=1;
		Fa[fx]=fy;
		inse(x,y,i);
		inse(y,x,i);
	}
	dep[1]=1;
	tim=log(n)/log(2);
	dfs(1);
	fo(i,1,k)ans[i]=INF;
	fo(i,1,n)
		fo(j,0,tim)val[i][j]=INF;
	fo(i,1,m)
	if (!used[i]){
		int x=f[i].x,y=f[i].y;
		int z=lca(x,y);
		add(x,dep[x]-dep[z],f[i].v);
		add(y,dep[y]-dep[z],f[i].v);
	}
	LL Ans=0;
	fd(i,n,1){
		int x=que[i];
		fd(j,tim,1)
		if (val[x][j]!=INF){
			val[x][j-1]=min(val[x][j-1],val[x][j]);
			val[fa[x][j-1]][j-1]=min(val[fa[x][j-1]][j-1],val[x][j]);
		}
		if (co[x]<0)ans[-co[x]]=val[x][0];
	}
	fo(i,1,k)if (ans[i]==INF){Ans=-1;break;}
	else Ans=Ans+ans[i];
	cout<<Ans<<endl;
	return 0;
}