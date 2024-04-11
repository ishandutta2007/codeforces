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

const int N=1000+19,M=30000+19;
const ll oo=1ll<<60;

struct Edge{
	int y,z,id,nxt;
} E[M*2];
int las[N],pre[N],dis[N];
int n,m,cnt,S,T,x,y,z,d;

struct sol{
	ll val;
	int x,y;
	bool operator < (const sol &B) {return val<B.val;}
} res;

void Link(int x,int y,int z,int id){
	E[cnt]=(Edge){y,z,id,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,id,las[y]};las[y]=cnt++;
}
void bfs(){
	static int Q[N];
	memset(dis,-1,sizeof(dis));dis[S]=1;
	int f=1,w=0;Q[1]=S;pre[S]=-1;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[y=E[i].y]==-1){
				dis[y]=dis[x]+1;
				pre[y]=i;
				Q[++f]=y;
			}
	}
}

namespace BCC{
	int dfn[N],low[N],bcc[N],stk[N],dis[N];
	int d,tot,num,res;
	vector<pii> V[N];
	void bfs(){
		static int Q[N];
		memset(dis,-1,sizeof(dis));dis[S]=1;
		int f=1,w=0;Q[1]=S;pre[S]=-1;
		while (f>w){
			int x=Q[++w];
			for (int i=las[x],y;~i;i=E[i].nxt)
				if (i!=d&&i!=(d^1)&&dis[y=E[i].y]==-1){
					dis[y]=dis[x]+1;
					Q[++f]=y;
				}
		}
	}
	void dfs(int x,int fa,int mn){
		int tmp;
		if (x==bcc[T]){
			res=mn;
			return;
		}
		For(i,0,V[x].size()){
			pii A=V[x][i];
			if (A.fi==fa) continue;
			tmp=mn;
			if (mn==-1||E[A.se].z<E[mn].z) tmp=A.se;
			dfs(A.fi,x,tmp);
		}
	}
	void Tarjan(int x,int fa){
		dfn[x]=low[x]=++tot;
		stk[++*stk]=x;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (i!=fa&&i!=d&&i!=(d^1)){
				if (!dfn[y=E[i].y]){
					Tarjan(y,i^1);
					low[x]=min(low[x],low[y]);
					if (low[y]>=dfn[y]){
						int u;num++;
						do{
							u=stk[(*stk)--];
							bcc[u]=num;
						} while (u!=y);
					}
				} else{
					//assert(!bcc[y]);
					low[x]=min(low[x],dfn[y]);
				}
			}
	}
	sol work(int del){
		memset(dfn,0,sizeof(dfn));
		memset(bcc,0,sizeof(bcc));
		d=del;tot=0;num=0;
		bfs();
		if (dis[T]==-1){
			return (sol){E[d].z,E[d].id,0};
		}
		For(i,1,n+1){
			if (!dfn[i]) Tarjan(i,-1);
		}
		num++;
		while (*stk) bcc[stk[(*stk)--]]=num;
		if (bcc[S]==bcc[T]){
			return (sol){oo,0,0};
		}
		For(i,1,num+1) V[i].clear();
		For(x,1,n+1){
			for (int i=las[x],y;~i;i=E[i].nxt)
				if (i!=d&&i!=(d^1))
					if (bcc[x]!=bcc[y=E[i].y]){
						V[bcc[x]].pb(mp(bcc[y],i));
					}
		}
		dfs(bcc[S],-1,-1);
		return (sol){E[d].z+E[res].z,E[d].id,E[res].id};
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),S=IN(),T=IN();
	For(i,1,m+1){
		x=IN(),y=IN(),z=IN();
		Link(x,y,z,i);
	}
	bfs();
	if (dis[T]==-1){
		puts("0");
		puts("0");
		return 0;
	}
	res.val=oo;
	for (int i=pre[T];~i;i=pre[E[i^1].y]){
		sol tmp=BCC::work(i);
		if (tmp<res) res=tmp;
	}
	if (res.val==oo){
		puts("-1");
		return 0;
	}
	printf("%I64d\n",res.val);
	if (res.y>0){
		puts("2");
		printf("%d %d\n",res.x,res.y);
	} else{
		puts("1");
		printf("%d\n",res.x);
	}
}