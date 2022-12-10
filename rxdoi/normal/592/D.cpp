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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],sz[N],vis[N];
int cnt,n,m,rt,e,mx,id,pt;
Vi V[N];

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	sz[x]=vis[x];
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
			if (sz[y]){
				V[x].pb(y);
				V[y].pb(x);e++;
			}
		}
}
void dfs(int x,int fa,int dis){
	int y;
	if (dis>mx||dis==mx&&x<id) mx=dis,id=x;
	For(i,0,V[x].size())
		if ((y=V[x][i])!=fa){
			dfs(y,x,dis+1);
		}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,n) Link(IN(),IN());
	For(i,1,m+1) vis[rt=IN()]=1;
	if (m==1){
		printf("%d\n",rt);
		printf("0\n");
		return 0;
	}
	dfs(rt,-1);

	mx=-oo;id=oo;pt=oo;
	dfs(rt,-1,0);
	pt=min(pt,id);

	mx=-oo;rt=id;id=oo;
	dfs(rt,-1,0);
	pt=min(pt,id);
	
	printf("%d\n",pt);
	printf("%d\n",2*e-mx);
}