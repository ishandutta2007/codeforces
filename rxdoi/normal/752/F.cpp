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
	int y,nxt;
} E[N*2];
int las[N],sz[N],vis[N];
int n,k,x,mn,mx,cen,c,cnt,rem;
Vi V[N],T;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void findcen(int x,int fa){
	int mx=0;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			findcen(y,x);
			sz[x]+=sz[y];
			mx=max(mx,sz[y]);
		}
	mx=max(mx,2*k-sz[x]);
	if (mx<mn) mn=mx,cen=x;
}
void dfs(int x,int fa,int c){
	if (vis[x]) V[c].pb(x);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x,c);
		}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();k=IN();
	For(i,1,n) Link(IN(),IN());
	For(i,0,2*k){
		x=IN();
		sz[x]=vis[x]=1;
	}
	mn=oo;
	findcen(1,-1);
	for (int i=las[cen];~i;i=E[i].nxt) dfs(E[i].y,cen,c),c++;
	if (vis[cen]) V[c++].pb(cen);
	printf("%d\n",1);
	printf("%d\n",cen);
	rem=2*k;
	For(i,0,c){
		rem-=int(V[i].size());
		while (!T.empty()&&!V[i].empty()&&int(T.size())+int(V[i].size())>rem){
			printf("%d %d %d\n",T.back(),V[i].back(),cen);
			T.pop_back();
			V[i].pop_back();
		}
		For(j,0,V[i].size()) T.pb(V[i][j]);
	}
}