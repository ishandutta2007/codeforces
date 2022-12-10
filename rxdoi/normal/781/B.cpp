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
string s1[N],s2[N];
char t1[N],t2[N];
int n;

namespace TwoSAT{
	const int N=500000;
	const int M=10000000;
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
			if (vis[2*i]==1) Ans[i]=1;
		}
	}
}

int main(){
	n=IN();
	For(i,0,n){
		scanf("%s%s",t1,t2);
		s1[i]+=t1[0];
		s1[i]+=t1[1];
		s1[i]+=t1[2];
		s2[i]+=t1[0];
		s2[i]+=t1[1];
		s2[i]+=t2[0];
	}
	TwoSAT::Init();
	For(i,0,n) For(j,i+1,n){
		if (s1[i]==s1[j]){
			TwoSAT::Add_Edge(2*i,2*j+1);
			TwoSAT::Add_Edge(2*j,2*i+1);
			TwoSAT::Add_Edge(2*i+1,2*j+1);
			TwoSAT::Add_Edge(2*j,2*i);
			TwoSAT::Add_Edge(2*j+1,2*i+1);
			TwoSAT::Add_Edge(2*i,2*j);
		}
		if (s1[i]==s2[j]){
			TwoSAT::Add_Edge(2*i,2*j);
			TwoSAT::Add_Edge(2*j+1,2*i+1);
		}
		if (s2[i]==s1[j]){
			TwoSAT::Add_Edge(2*i+1,2*j+1);
			TwoSAT::Add_Edge(2*j,2*i);
		}
		if (s2[i]==s2[j]){
			TwoSAT::Add_Edge(2*i+1,2*j);
			TwoSAT::Add_Edge(2*j+1,2*i);
		}
	}
	if (!(TwoSAT::Main(2*n))) return puts("NO"),0;
	TwoSAT::getsol();
	puts("YES");
	For(i,0,n) puts(Ans[i]?s1[i].c_str():s2[i].c_str());
}