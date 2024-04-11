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

const int N=1000+19;
const int M=10000+19;
const ll oo=1ll<<50;

struct edge{
	int x,y;
	ll z;
} e[M];

struct Edge{
	int y;
	ll z;
	int nxt;
} E[M*2];
int las[N],b[M];
int n,m,L,S,T,id,cnt;
ll tmp,l,r,res;

void Link(int x,int y,ll z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
ll SPFA(){
	static int Q[N*N],vis[N];
	static ll dis[N];
	For(i,0,n) las[i]=-1;
	cnt=0;
	For(i,1,m+1) Link(e[i].x,e[i].y,e[i].z);
	For(i,0,n) dis[i]=oo;dis[S]=0;
	int f=1,w=0;Q[1]=S;
	while (f>w){
		int x=Q[++w];vis[x]=0;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[x]+E[i].z<dis[y=E[i].y]){
				dis[y]=dis[x]+E[i].z;
				if (!vis[y]) vis[y]=1,Q[++f]=y;
			}
	}
	return dis[T];
}

int main(){
	n=IN();m=IN();L=IN(),S=IN(),T=IN();
	For(i,1,m+1){
		e[i]=(edge){IN(),IN(),IN()};
		if (e[i].z==0) b[i]=1;
	}
	
	For(i,1,m+1) if (b[i]) e[i].z=oo;
	tmp=SPFA();
	if (tmp<L) return puts("NO"),0;
	if (tmp==L){
		puts("YES");
		For(i,1,m+1) printf("%d %d %I64d\n",e[i].x,e[i].y,e[i].z);
		return 0;
	}
	
	For(i,1,m+1) if (b[i]) e[i].z=1;
	tmp=SPFA();
	if (tmp>L) return puts("NO"),0;
	if (tmp==L){
		puts("YES");
		For(i,1,m+1) printf("%d %d %I64d\n",e[i].x,e[i].y,e[i].z);
		return 0;
	}
	l=0,r=m;
	while (l<=r){
		int mid=(l+r>>1);
		For(i,1,m+1) if (b[i]) e[i].z=(i<=mid?1:oo);
		if (SPFA()>L) id=mid+1,l=mid+1;else r=mid-1;
	}
	For(i,1,m+1) if (b[i]) e[i].z=(i<id?1:oo);
	//if (n==989) printf("%d\n",id);
	assert(b[id]);
	l=1,r=oo;
	while (l<=r){
		ll mid=(l+r>>1);
		e[id].z=mid;
		if (SPFA()<=L) res=mid,l=mid+1;else r=mid-1;
	}
	e[id].z=res;
	assert(SPFA()==L);
	puts("YES");
	For(i,1,m+1) printf("%d %d %I64d\n",e[i].x,e[i].y,e[i].z);
}