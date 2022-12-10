#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
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
	int y,nxt;
} E[N*2];
int A[N],las[N],dfn[N],scc[N],sz[N],wei[N],stk[N],low[N];
int n,m,h,x,y,tot,cnt,top,num,ans,w;
Vi V[N];

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void Tarjan(int x){
	stk[++top]=x;
	low[x]=dfn[x]=++tot;
	for (int i=las[x],y;~i;i=E[i].nxt){
		if (!dfn[y=E[i].y]){
			Tarjan(y);
			low[x]=min(low[x],low[y]);
		} else{
			if (!scc[y]) low[x]=min(low[x],dfn[y]);
		}
	}
	if (dfn[x]==low[x]){
		int u;
		num++;
		do{
			u=stk[top--];
			scc[u]=num;
			sz[num]++;
			V[num].pb(u);
		} while (u!=x);
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),h=IN();
	For(i,1,n+1) A[i]=IN();
	while (m--){
		x=IN(),y=IN();
		if ((A[x]+1)%h==A[y]){
			Add_Edge(x,y);
		}
		if ((A[y]+1)%h==A[x]){
			Add_Edge(y,x);
		}
	}
	For(i,1,n+1) if (!dfn[i]) Tarjan(i);
	For(x,1,n+1){
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (scc[x]!=scc[y=E[i].y]){
				wei[scc[x]]=1;
			}
	}
	ans=oo;
	For(i,1,num+1) if (!wei[i]&&sz[i]<ans) ans=sz[i],w=i;
	printf("%d\n",ans);
	for (int x:V[w]) printf("%d ",x);
	puts("");
}