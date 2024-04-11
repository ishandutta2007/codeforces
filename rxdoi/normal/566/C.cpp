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
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (!vis[y=E[i].y])
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

const int N=200000+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,z,nxt;
} E[N*2];
int las[N],w[N],sz[N],vis[N];
int n,cnt,pos,fcen,mn,cen,x,y,z;
db res=1e60,tmp,mx;

void Link(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
void calc(int x,int fa,int d){
	tmp+=w[x]*sqrt(1.0*d*d*d);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			calc(y,x,d+E[i].z);
		}
}
void dfs(int x,int fa,int d){
	tmp+=w[x]*sqrt(d);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x,d+E[i].z);
		}
}
void findcen(int x,int fa,int n){
	int tmp=0;
	sz[x]=1;
	Rep(x) if (y!=fa){
		findcen(y,x,n);
		sz[x]+=sz[y];
		tmp=max(tmp,sz[y]);
	}
	tmp=max(tmp,n-sz[x]);
	if (tmp<mn) mn=tmp,cen=x,fcen=fa;
}
void solve(int x,int n){
	mn=oo;
	findcen(x,-1,n);
	vis[x=cen]=1;
	if (~fcen) sz[fcen]=n-sz[x];
	tmp=0;
	calc(x,-1,0);
	if (tmp<res) res=tmp,pos=x;
	int p=-1;
	mx=-1e60;
	Rep(x){
		tmp=0;
		dfs(y,x,E[i].z);
		if (tmp>mx) mx=tmp,p=y;
	}
	if (~p) solve(p,sz[p]);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n+1) w[i]=IN();
	For(i,1,n){
		x=IN(),y=IN(),z=IN();
		Link(x,y,z);
	}
	solve(1,n);
	printf("%d %.20lf\n",pos,res);
}