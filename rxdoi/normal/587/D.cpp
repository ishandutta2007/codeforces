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

const int N=500000;

Vi V;
int Ans[N];

namespace TwoSAT{
	const int N=500000;
	const int M=1000000;
	struct Edge{
		int y,nxt;
	} E[M];
	Vi res;
	int las[N],dfn[N],low[N],scc[N],stk[N],seq[N],vis[N];
	int cnt,id,num,n;
	void Init(){
		memset(las,-1,sizeof(las));
		memset(scc,0,sizeof(scc));
		memset(dfn,0,sizeof(dfn));
		cnt=0;id=0;num=0;*seq=0;
	}
	void Add_Edge(int x,int y){
		E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	}
	void Tarjan(int x){
		low[x]=dfn[x]=++id;
		stk[++*stk]=x;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (!dfn[y=E[i].y]){
				Tarjan(y);
				low[x]=min(low[x],low[y]);
			} else{
				if (!scc[y]) low[x]=min(low[x],dfn[y]);
			}
		if (low[x]==dfn[x]){
			int u;num++;
			do{
				u=stk[(*stk)--];
				seq[++*seq]=u;
				scc[u]=num;
			} while (u!=x);
		}
	}
	bool Main(int __n){
		n=__n;
		For(i,0,n){
			if (!dfn[i]) Tarjan(i);
		}
		For(i,0,n){
			if (scc[i]==scc[i^1]) return 0;
		}
		return 1;
	}
	void dfs(int x){
		if (~vis[x]) return;
		vis[x]=1;
		for (int i=las[x];~i;i=E[i].nxt) dfs(E[i].y);
	}
	void getsol(){
		memset(vis,-1,sizeof(vis));
		for (int i=*seq,x;i;i--)
			if (vis[x=seq[i]]==-1){
				vis[x]=0;
				dfs(x^1);
			}
		For(i,0,n/2){
			if (vis[2*i]==1) Ans[i+1]=1;
		}
	}
}

struct Edge{
	int x,y,c,t;
} E[N];
map<int,Vi> M[N];
typedef map<int,Vi>::iterator It;
int A[N],id[N],pre[N];
int n,m,l,r,res=-1,num;

bool check(int T){
	TwoSAT::Init();
	For(i,1,m+1) id[i]=2*(i-1);
	For(i,1,m+1){
		if (E[i].t>T) TwoSAT::Add_Edge(id[i],id[i]^1);
	}
	num=2*m;
	For(x,1,n+1){
		*A=0;
		for (It it=M[x].begin();it!=M[x].end();it++){
			if (it->se.size()==1){
				A[++*A]=it->se[0];
			} else{
				int x=it->se[0],y=it->se[1];
				TwoSAT::Add_Edge(id[x]^1,id[y]);
				TwoSAT::Add_Edge(id[y]^1,id[x]);
				A[++*A]=x;
				A[++*A]=y;
			}
		}
		pre[0]=num;num+=2;
		For(i,1,*A+1){
			int x=A[i];
			pre[i]=num;num+=2;
			TwoSAT::Add_Edge(pre[i-1],pre[i]);
			TwoSAT::Add_Edge(pre[i]^1,pre[i-1]^1);
			TwoSAT::Add_Edge(id[x],pre[i]);
			TwoSAT::Add_Edge(pre[i]^1,id[x]^1);
			TwoSAT::Add_Edge(pre[i-1],id[x]^1);
			TwoSAT::Add_Edge(id[x],pre[i-1]^1);
		}
		/*
		For(i,1,*A+1)
			For(j,i+1,*A+1){
				int x=A[i],y=A[j];
				TwoSAT::Add_Edge(id[x],id[y]^1);
				TwoSAT::Add_Edge(id[y],id[x]^1);
			}
		*/
	}
	return TwoSAT::Main(num);
}

int main(){
	n=IN(),m=IN();
	For(i,1,m+1){
		E[i]=(Edge){IN(),IN(),IN(),IN()};
		M[E[i].x][E[i].c].pb(i);
		M[E[i].y][E[i].c].pb(i);
		if (M[E[i].x][E[i].c].size()>2) return puts("No"),0;
		if (M[E[i].y][E[i].c].size()>2) return puts("No"),0;
	}
	l=0,r=1e9;
	while (l<=r){
		int mid=(l+r>>1);
		if (check(mid)) res=mid,r=mid-1;else l=mid+1;
	}
	if (~res){
		puts("Yes");
		printf("%d ",res);
		check(res);
		TwoSAT::getsol();
		For(i,1,m+1){
			if (Ans[i]) V.pb(i);
		}
		printf("%d\n",V.size());
		For(i,0,V.size()) printf("%d ",V[i]);
		puts("");
	} else{
		puts("No");
	}
}