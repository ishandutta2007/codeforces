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

const int top=1e7;
const int M=top+19;
const int N=4e5+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

bool vis[M];
int pri[M],mnp[M];

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],dep[N],sz[N],son[N],tp[N],fa[N],I[N],O[N],ans[N],C[N],T[N];
int cnt,n,q,a,b,x,Time,tot;
vector<pii> V[M];

struct QType{
	int id,pt,c;
	bool operator < (const QType &B) const{
		return c<B.c;
	}
};vector<QType> Q[M];

void Add(int x,int v){
	for (;x<=n;x+=x&-x){
		if (T[x]!=Time) T[x]=Time,C[x]=0;
		C[x]+=v;
	}
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x){
		if (T[x]==Time) res+=C[x];
	}
	return res;
}

void Init(){
	For(i,2,top+1){
		if (!vis[i]){
			pri[++*pri]=i;
			mnp[i]=i;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			mnp[pri[j]*i]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x){
	sz[x]=1;
	I[x]=++tot;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
		}
	O[x]=tot;
}
void dfs(int x,int anc){
	tp[x]=anc;
	if (son[x]) dfs(son[x],anc);
	for (int i=las[x],y;~i;i=E[i].nxt){
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
	}
}
int LCA(int x,int y){
	int a=tp[x],b=tp[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		y=fa[b],b=tp[y];
	}
	return dep[x]<dep[y]?x:y;
}
void add_query(int i,int pt,int x){
	if (pt==0) return;
	while (x>1){
		int c=0,w=mnp[x];
		while (x%w==0) x/=w,c++;
		Q[w].pb((QType){i,pt,c});
	}
}

int main(){
	memset(las,-1,sizeof(las));
	Init();
	n=IN();
	For(i,1,n) Link(IN(),IN());
	dfs(1);
	dfs(1,1);
	For(i,1,n+1){
		x=IN();
		while (x>1){
			int c=0,w=mnp[x];
			while (x%w==0) x/=w,c++;
			V[w].pb(mp(c,i));
		}
	}
	q=IN();
	For(i,1,q+1){
		a=IN(),b=IN(),x=IN();
		add_query(i,a,x);
		add_query(i,b,x);
		add_query(i+q,LCA(a,b),x);
		add_query(i+q,fa[LCA(a,b)],x);
	}
	For(i,1,2*q+1) ans[i]=1;
	For(i,2,top+1)
		if (!vis[i]&&Q[i].size()){
			sort(V[i].begin(),V[i].end());
			sort(Q[i].begin(),Q[i].end());
			int c=0;
			Time++;
			for (QType T:Q[i]){
				for (;c<V[i].size()&&V[i][c].fi<T.c;c++){
					int x=V[i][c].se;
					Add(I[x],V[i][c].fi);
					Add(O[x]+1,-V[i][c].fi);
				}
				ans[T.id]=1ll*ans[T.id]*Pow(i,Qry(I[T.pt]))%p;
			}
			Time++;
			c=int(V[i].size())-1;
			for (int j=int(Q[i].size())-1;~j;j--){
				QType T=Q[i][j];
				for (;c>=0&&V[i][c].fi>=T.c;c--){
					int x=V[i][c].se;
					Add(I[x],1);
					Add(O[x]+1,-1);
				}
				ans[T.id]=1ll*ans[T.id]*Pow(i,1ll*T.c*Qry(I[T.pt])%(p-1))%p;
			}
		}
	For(i,1,q+1){
		int tmp=1ll*ans[i]*Pow(ans[i+q],p-2)%p;
		printf("%d\n",tmp);
	}
}