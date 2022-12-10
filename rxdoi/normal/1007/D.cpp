#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lf else if
#define Mid ((L+R)>>1)

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

const int N=2e5+19;
const int Top=10000000;

bool st;

namespace TwoSAT{
	const int N=10000000;
	const int M=20000000;
	
	struct Edge{
		int y,nxt;
	} E[M];
	char vis[N];
	int las[N],scc[N],stk[N],dfn[N],low[N],seq[N];
	int n,cnt,top,num,tot;
	
	void Add_Edge(int x,int y){
		E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	}
	void Add(int x,int y){
		Add_Edge(x,y);
		Add_Edge(y^1,x^1);
	}
	void Init(){
		memset(las,-1,sizeof(las));
		memset(vis,-1,sizeof(vis));
	}
	void Tarjan(int x){
		dfn[x]=low[x]=++tot;
		stk[++top]=x;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (!dfn[y=E[i].y]){
				Tarjan(y);
				low[x]=min(low[x],low[y]);
			} lf (!scc[y]){
				low[x]=min(low[x],dfn[y]);
			}
		if (low[x]==dfn[x]){
			int u;
			num++;
			do{
				u=stk[top--];
				scc[u]=num;
				seq[++*seq]=u;
			} while (u!=x);
		}
	}
	void dfs(int x){
		vis[x]=1;
		vis[x^1]=0;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (vis[y=E[i].y]==-1){
				dfs(y);
			}
	}
	void Main(int __n,int m){
		n=__n;
		For(i,0,n) if (!dfn[i]) Tarjan(i);
		For(i,0,n) if (scc[i]==scc[i^1]){
			puts("NO");
			return;
		}
		for (int i=*seq;i;i--){
			int x=seq[i];
			if (vis[x]==-1) dfs(x^1);
		}
		puts("YES");
		For(i,0,m){
			printf("%d\n",vis[4*i+1]==1?1:2);
		}
	}
}

struct node *null;
struct node{
	node *L,*R;
	int sum,pt;
} Nd[Top],*cur=Nd+1,*rt[N];

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],a[N],b[N],c[N],d[N];
int n,m,cnt,tot,T,pre;
Vi V[N];

bool ed;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
node *Modify(node *y,int L,int R,int Qx){
	node *x=cur++;
	*x=*y;
	x->pt=tot;
	tot+=2;
	if (L==R){
		x->sum^=1;
		return x;
	}
	if (Qx<=Mid){
		x->L=Modify(y->L,L,Mid,Qx);
	} else{
		x->R=Modify(y->R,Mid+1,R,Qx);
	}
	x->sum=x->L->sum+x->R->sum;
	return x;
}
node *Merge(node *a,node *b,int L,int R){
	if (a==null) return b;
	if (b==null) return a;
	node *x=cur++;
	x->pt=tot;
	tot+=2;
	if (L==R){
		x->sum=a->sum^b->sum;
		return x;
	}
	x->L=Merge(a->L,b->L,L,Mid);
	x->R=Merge(a->R,b->R,Mid+1,R);
	x->sum=x->L->sum+x->R->sum;
	return x;
}
void work(node *x,int L,int R){
	if (x->pt<pre) return;
	if (L==R){
		if (x->sum) TwoSAT::Add(x->pt,2*L);
		return;
	}
	work(x->L,L,Mid);
	work(x->R,Mid+1,R);
	if (x->L->sum) TwoSAT::Add(x->pt,x->L->pt);
	if (x->R->sum) TwoSAT::Add(x->pt,x->R->pt);
	if (x->L->sum&&x->R->sum){
		TwoSAT::Add(x->L->pt^1,x->R->pt);
	}
}
void dfs(int x,int fa){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
		}
	pre=tot;
	rt[x]=null;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			rt[x]=Merge(rt[x],rt[y],0,2*m-1);
		}
	for (int i:V[x]){
		rt[x]=Modify(rt[x],0,2*m-1,i);
	}
	work(rt[x],0,2*m-1);
}

int main(){
	dprintf("%d\n",(&ed-&st)/1000000);
	TwoSAT::Init();
	null=Nd;
	*null=(node){null,null,0,-1};
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	m=IN();
	For(i,0,m){
		a[i]=IN(),b[i]=IN(),c[i]=IN(),d[i]=IN();
		TwoSAT::Add(4*i,4*i+3);
		TwoSAT::Add(4*i+1,4*i+2);
		V[a[i]].pb(2*i);
		V[b[i]].pb(2*i);
		V[c[i]].pb(2*i+1);
		V[d[i]].pb(2*i+1);
	}
	tot=4*m;
	dfs(1,-1);
	TwoSAT::Main(tot,m);
}