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

const int N=5000+19;
const int oo=32767;

struct Edge{
	int y,nxt;
} E[N*2];
short g[2][N][2*N][2];
int las[N],d[N],sz[N],s[N];
int cnt,n;

void U(short &x,short y) {x=min(x,y);}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
	d[x]++,d[y]++;
}
void dfs(int x,int fa){
	int t=0,tmp;
	if (d[x]==1){
		g[t][x][N+1][1]=g[t][x][N-1][0]=0;
	} else{
		g[t][x][N][1]=g[t][x][N][0]=0;
	}
	sz[x]=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			tmp=sz[x]+sz[y];
			For(a,-tmp,tmp+1){
				For(b,0,2) g[t^1][x][a+N][b]=oo;
			}
			For(a,-sz[x],sz[x]+1) For(b,0,2)
				if (g[t][x][a+N][b]<n){
					For(c,-sz[y],sz[y]+1) For(d,0,2)
						if (g[s[y]][y][c+N][d]<n){
							U(g[t^1][x][a+c+N][b],g[t][x][a+N][b]+g[s[y]][y][c+N][d]+(b!=d));
						}
				}
			sz[x]+=sz[y];
			t^=1;
		}
	s[x]=t;
}

int main(){
	memset(las,-1,sizeof(las));
	memset(g,64,sizeof(g));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	printf("%d\n",min(g[s[1]][1][N][0],g[s[1]][1][N][1]));
}