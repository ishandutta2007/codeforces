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
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=5000+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,nxt;
} E[N*2];
int f[N][N][2],g[N][2];
int sz[N],las[N],c[N],d[N];
int cnt,n,b,res;

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void Upd(int &x,int y){
	if (y<x) x=y;
}
void dp(int x){
	sz[x]=1;
	for (int i=las[x];~i;i=E[i].nxt) dp(E[i].y);
	f[x][0][0]=0;
	f[x][1][0]=c[x];
	f[x][1][1]=c[x]-d[x];
	for (int i=las[x],y;~i;i=E[i].nxt){
		y=E[i].y;
		for (int a=0;a<=sz[x]+sz[y];a++) For(u,0,2) g[a][u]=oo;
		for (int a=0;a<=sz[x];a++) For(u,0,2) if (f[x][a][u]<oo)
			for (int b=0;b<=sz[y];b++) For(v,0,2) if (f[y][b][v]<oo&&!(u==0&&v==1)){
				Upd(g[a+b][u],f[x][a][u]+f[y][b][v]);
			}
		sz[x]+=sz[y];
		for (int a=0;a<=sz[x];a++) For(u,0,2) f[x][a][u]=g[a][u];
	}
}

int main(){
	memset(f,64,sizeof(f));
	memset(las,-1,sizeof(las));
	n=IN(),b=IN();
	For(i,1,n+1){
		c[i]=IN(),d[i]=IN();
		if (i>1) Add_Edge(IN(),i);
	}
	dp(1);
	For(i,1,n+1){
		if (min(f[1][i][0],f[1][i][1])<=b) res=i;
	}
	printf("%d\n",res);
}