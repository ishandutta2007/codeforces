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

const int N=5000+19;
const int M=200000;
const ll oo=1ll<<60;
const int inf=(1<<30)-1;

struct Edge{
	int y,f,c,nxt;
} E[M];
ll dis[N],res;
int vis[N],pre[N],las[N];
int A[N],B[N];
int n,K,cnt,S,T,s1,s2,t,tot;

void Add_Edge(int x,int y,int f,int c){
	E[cnt]=(Edge){y,f,c,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,0,-c,las[y]};las[y]=cnt++;
}
bool spfa(){
	static int Q[N*100];
	int f=1,w=0;Q[1]=S;
	For(i,1,tot+1) dis[i]=oo;
	dis[S]=0;pre[S]=-1;
	while (f>w){
		int x=Q[++w];vis[x]=0;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (E[i].f&&dis[x]+E[i].c<dis[y=E[i].y]){
				dis[y]=dis[x]+E[i].c;
				pre[y]=i;
				if (!vis[y]){
					vis[y]=1;
					Q[++f]=y;
				}
			}
	}
	return dis[T]!=oo;
}
void Update(){
	for (int i=pre[T];~i;i=pre[E[i^1].y]) E[i].f--,E[i^1].f++;
	res+=dis[T];
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),K=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	tot=2*n;
	S=++tot,s1=++tot,s2=++tot,T=++tot;
	For(i,1,n+1){
		Add_Edge(s2,i,1,A[i]);
		Add_Edge(i+n,T,1,B[i]);
		Add_Edge(i,i+n,inf,0);
	}
	For(i,1,n){
		Add_Edge(i+n,i+1+n,inf,0);
	}
	Add_Edge(S,s2,K,0);
	Add_Edge(s1,T,K,0);
	while (spfa()) Update();
	cout<<res<<endl;
}