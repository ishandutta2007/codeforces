#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=500+19;
const int M=20000+19;
const int oo=(1<<30)-1;
const int top=200000;

struct Edge{
	int y,f,nxt;
} E[M];
int las[N],Q[N],dis[N],p[N],c[N],l[N];
int cnt,S,T,K,n,L,R,res;
int isp[top+19];

void Add_Edge(int x,int y,int f){
	E[cnt]=(Edge){y,f,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,0,las[y]};las[y]=cnt++;
}
bool bfs(){
	memset(dis,-1,sizeof(dis));
	dis[S]=1;
	int f=1,w=0;Q[1]=S;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (E[i].f&&dis[y=E[i].y]==-1){
				dis[y]=dis[x]+1;
				Q[++f]=y;
				if (y==T) return 1;
			}
	}
	return 0;
}
int dinic(int x,int flow){
	if (x==T||!flow) return flow;
	int res=0;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if (E[i].f&&dis[y=E[i].y]==dis[x]+1){
			int tmp=dinic(y,min(flow,E[i].f));
			flow-=tmp,res+=tmp,E[i].f-=tmp,E[i^1].f+=tmp;
		}
	if (!res) dis[x]=-1;
	return res;
}
bool check(int mid){
	int res=0;
	vector<pii> V[2];
	For(i,1,n+1)
		if (l[i]<=mid){
			if (c[i]==1){
				res=max(res,p[i]);
			} else{
				V[c[i]&1].pb(mp(c[i],p[i]));
			}
		}
	if (res){
		V[1].pb(mp(1,res));
		res=0;
	}
	memset(las,-1,sizeof(las));
	cnt=0;
	S=V[0].size()+V[1].size();
	T=S+1;
	For(i,0,V[0].size())
		For(j,0,V[1].size())
			if (isp[V[0][i].fi+V[1][j].fi]){
				Add_Edge(i,j+V[0].size(),oo);
			}
	For(i,0,V[0].size()){
		Add_Edge(S,i,V[0][i].se);
		res+=V[0][i].se;
	}
	For(i,0,V[1].size()){
		Add_Edge(i+V[0].size(),T,V[1][i].se);
		res+=V[1][i].se;
	}
	while (bfs()) res-=dinic(S,oo);
	return res>=K;
}

int main(){
	For(i,1,top+1) isp[i]=1;
	For(i,2,top+1)
		if (isp[i]){
			for (int j=i+i;j<=top;j+=i) isp[j]=0;
		}
	n=IN(),K=IN();
	For(i,1,n+1){
		p[i]=IN(),c[i]=IN(),l[i]=IN();
	}
	L=1,R=n,res=-1;
	while (L<=R){
		int mid=(L+R)/2;
		if (check(mid)) res=mid,R=mid-1;else L=mid+1;
	}
	printf("%d\n",res);
}