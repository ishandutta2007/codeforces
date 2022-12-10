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
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

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

const int N=4000000+19;
const int M=6000000;
const ll oo=1ll<<60;

struct Edge{
	int y,z,nxt;
} E[M];
int p1[N],p2[N],las[N];
int n,m,cnt,s,tot,x,y,z,Ql,Qr,Qx;

void Add_Edge(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
}

void Build(int x,int L,int R){
	p1[x]=++tot;
	p2[x]=++tot;
	if (L==R){
		Add_Edge(p1[x],L,0);
		Add_Edge(L,p2[x],0);
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	Add_Edge(p1[x],p1[Lsn],0);
	Add_Edge(p1[x],p1[Rsn],0);
	Add_Edge(p2[Lsn],p2[x],0);
	Add_Edge(p2[Rsn],p2[x],0);
}
void Query1(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Add_Edge(Qx,p1[x],z);
		return;
	}
	if (Ql<=Mid) Query1(Lsn,L,Mid);
	if (Qr>Mid) Query1(Rsn,Mid+1,R);
}
void Query2(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Add_Edge(p2[x],Qx,z);
		return;
	}
	if (Ql<=Mid) Query2(Lsn,L,Mid);
	if (Qr>Mid) Query2(Rsn,Mid+1,R);
}

struct node{
	int x;
	ll dis;
	bool operator < (const node &B) const{
		return dis>B.dis;
	}
};priority_queue<node> Q;
ll dis[N];

void Dijkstra(int s){
	For(i,1,tot+1) dis[i]=oo;
	dis[s]=0;
	Q.push((node){s,0});
	while (!Q.empty()){
		int x=Q.top().x;
		ll d=Q.top().dis;
		Q.pop();
		if (d!=dis[x]) continue;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[x]+E[i].z<dis[y=E[i].y]){
				dis[y]=dis[x]+E[i].z;
				Q.push((node){y,dis[y]});
			}
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),s=IN();
	tot=n;
	Build(1,1,n);
	while (m--){
		int o=IN();
		if (o==1){
			x=IN(),y=IN(),z=IN();
			Add_Edge(x,y,z);
		}
		if (o==2){
			Qx=IN(),Ql=IN(),Qr=IN(),z=IN();
			Query1(1,1,n);
		}
		if (o==3){
			Qx=IN(),Ql=IN(),Qr=IN(),z=IN();
			Query2(1,1,n);
		}
	}
	Dijkstra(s);
	For(i,1,n+1){
		printf("%I64d ",dis[i]==oo?-1:dis[i]);
	}
	puts("");
}