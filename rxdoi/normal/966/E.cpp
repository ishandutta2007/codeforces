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

const int N=3e5+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,nxt;
} E[N*2];
typedef int one[N];
one las,val,A,P,dep,fa,sz,son,top,dfn,seq,pa,vis,pos,plu,sum,wei;
int n,q,cnt,tot,ans,S;
vector<pii> T[N];

int c[512];

bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x){
	dfn[x]=++tot;
	seq[tot]=x;
	sz[x]=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
		}
}
void dfs(int x,int anc){
	top[x]=anc;
	if (son[x]) dfs(son[x],anc);
	for (int i=las[x],y;~i;i=E[i].nxt){
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
	}
}
int LCA(int x,int y){
	int a=top[x],b=top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		y=fa[b],b=top[y];
	}
	return dep[x]<dep[y]?x:y;
}
void Work(int l,int r){
	*P=0;
	For(i,l,r+1){
		if (abs(A[i])!=1) P[++*P]=fa[abs(A[i])];
		P[++*P]=abs(A[i]);
	}
	sort(P+1,P+*P+1,cmp);
	*P=unique(P+1,P+*P+1)-P-1;
	For(i,1,*P) P[*P+i]=LCA(P[i],P[i+1]);
	P[*P*=2]=1;
	sort(P+1,P+*P+1,cmp);
	*P=unique(P+1,P+*P+1)-P-1;
	memset(vis,0,sizeof(vis));
	For(i,1,*P+1){
		Vi V,Q;
		int w=P[i],x=P[i];
		while (x&&!vis[x]){
			vis[x]=1;
			if (!wei[x]&&x!=w) V.pb(sum[x]);
			x=fa[x];
		}
		memset(c,0,sizeof(c));
		for (int j:V) c[(j+n)&511]++;
		For(j,1,512) c[j]+=c[j-1];
		Q.resize(V.size());
		for (int j:V) Q[--c[(j+n)&511]]=j;
		reverse(Q.begin(),Q.end());
		memset(c,0,sizeof(c));
		for (int j:Q) c[(j+n)>>9]++;
		For(j,1,512) c[j]+=c[j-1];
		for (int j:Q) V[--c[(j+n)>>9]]=j;
		//sort(V.begin(),V.end());
		T[w].clear();
		int las=-oo;
		for (int j:V){
			if (j==las) T[w].back().se++;else T[w].pb(mp(j,1));
			las=j;
		}
		pos[w]=-1;
		For(j,1,T[w].size()) T[w][j].se+=T[w][j-1].se;
		For(j,0,T[w].size()) if (T[w][j].fi<0) pos[w]=j;
		pa[w]=x;
	}
	ans=0;
	For(i,1,n+1) if (sum[i]<0&&!wei[i]) ans++;
	memset(plu,0,sizeof(plu));
	For(i,l,r+1){
		int u=abs(A[i]);
		for (int w=fa[u];w;w=pa[w]){
			if (~pos[w]) ans-=T[w][pos[w]].se;
			if (!wei[w]&&sum[w]+plu[w]<0) ans--;
			plu[w]+=(A[i]>0?-1:1);
			if (!wei[w]&&sum[w]+plu[w]<0) ans++;
			while (pos[w]+1<T[w].size()&&T[w][pos[w]+1].fi+plu[w]<0) pos[w]++;
			while (pos[w]>=0&&T[w][pos[w]].fi+plu[w]>=0) pos[w]--;
			if (~pos[w]) ans+=T[w][pos[w]].se;
		}
		if (!wei[u]&&sum[u]+plu[u]<0) ans--;
		wei[u]^=1;
		if (!wei[u]&&sum[u]+plu[u]<0) ans++;		
		printf("%d ",ans);
	}
	
}

int main(){
	//freopen("E.in","r",stdin);
	memset(las,-1,sizeof(las));
	n=IN(),q=IN();
	For(i,2,n+1) Link(IN(),i);
	For(i,1,n+1) val[i]=IN();
	For(i,1,q+1) A[i]=IN();
	dfs(1);
	dfs(1,1);
	S=320;
	For(i,1,n+1) sum[i]=val[i];
	for (int l=1,r;l<=q;l=r+1){
		r=min(l+S-1,q);
		Work(l,r);
		memset(sum,0,sizeof(sum));
		For(i,1,r+1){
			if (A[i]>0) sum[fa[A[i]]]--;else sum[fa[-A[i]]]++;
		}
		for (int i=tot;i;i--){
			int x=seq[i];
			sum[fa[x]]+=sum[x];
		}
		For(i,1,n+1) sum[i]+=val[i];
	}
	puts("");
}