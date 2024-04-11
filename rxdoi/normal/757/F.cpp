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

const int N=200000+19;
const int M=300000+19;

struct Edge{
	int y,z,nxt;
} E[M*2];
ll dis[N];
int fa[20][N];
int las[N],vis[N],T[N],dep[N],sz[N];
int n,m,s,cnt,x,y,z,res;
Vi V[N];

struct nd{
	int x;
	ll dis;
	bool operator < (const nd &B) const {return dis>B.dis;}
};priority_queue<nd> Q;

void Link(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
void Dijkstra(){
	For(i,1,n+1) dis[i]=1ll<<60;
	dis[s]=0;
	Q.push((nd){s,0});
	while (!Q.empty()){
		x=Q.top().x;Q.pop();
		if (vis[x]) continue;
		vis[x]=1;T[++*T]=x;
		for (int i=las[x],y;~i;i=E[i].nxt){
			if (dis[x]+E[i].z<dis[y=E[i].y]){
				dis[y]=dis[x]+E[i].z;
				Q.push((nd){y,dis[y]});
				V[y].clear();
			}
			if (dis[x]+E[i].z==dis[y=E[i].y]){
				V[y].pb(x);
			}
		}
	}
}
int LCA(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	for (int k=dep[y]-dep[x],i=0;i<20;i++) if (k>>i&1) y=fa[i][y];
	if (x==y) return x;
	for (int i=19;~i;i--){
		if (fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	}
	return fa[0][x];
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),s=IN();
	For(i,0,m){
		x=IN(),y=IN(),z=IN();
		Link(x,y,z);
	}
	Dijkstra();
	For(i,2,*T+1){
		int x=T[i];
		for (int y:V[x])
			if (!fa[0][x]){
				fa[0][x]=y;
			} else{
				fa[0][x]=LCA(fa[0][x],y);
			}
		dep[x]=dep[fa[0][x]]+1;
		For(t,1,20) fa[t][x]=fa[t-1][fa[t-1][x]];
	}
	for (int i=*T;i>1;i--){
		int x=T[i];
		sz[x]++;
		sz[fa[0][x]]+=sz[x];
		res=max(res,sz[x]);
	}
	printf("%d\n",res);
}