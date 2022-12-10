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
#define lf else if

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

const int L=1000+19;
const int N=L*L;

char s[L][L];
int id[L][L];
int fa[N];
int n,m,q,type,S,T,x,y;
int stk[2*N],top,res,tot;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

set<int> M[N];
Vi V[N];
vector<pii> tra;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int getf2(int x){
	return fa[x]==x?x:getf2(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y;
}
void Merge(int x,int y){
	x=getf2(x),y=getf2(y);
	if (x!=y){
		stk[++top]=x;
		stk[++top]=-y;
		fa[x]=y;
		V[y].pb(-x);
	}
}
void dfs(int x,Vi &res){
	For(i,0,V[x].size()){
		int y=V[x][i];
		if (y>0) res.pb(y);else dfs(-y,res);
	}
}
int Main(int Te){
	for (int k=IN();k--;){
		x=IN(),y=IN();
		if (s[x][y]=='#') continue;
		For(k,0,8){
			int u=x+dx[k],v=y+dy[k];
			if (s[u][v]!='#') continue;
			Merge(id[x][y],id[u][v]);
		}
		if (x==n||y==1) Merge(S,id[x][y]);
		if (x==1||y==m) Merge(T,id[x][y]);
		s[x][y]='#';
		tra.pb(mp(x,y));
	}
	if (getf2(S)==getf2(T)) return 0;
	Vi Vs,Vt;
	dfs(getf2(S),Vs);
	dfs(getf2(T),Vt);
	For(i,0,Vs.size()){
		For(j,0,Vt.size()){
			int a=Vs[i],b=Vt[j];
			if (a>b) swap(a,b);
			if (M[a].find(b)!=M[a].end()) return 0;
		}
	}
	For(i,0,tra.size()){
		int x=tra[i].fi,y=tra[i].se;
		for (int u=x-2;u<=x+2;u++)
			for (int v=y-2;v<=y+2;v++){
				if (u<0||u>n+1||v<0||v>m+1) continue;
				if (getf2(id[x][y])==getf2(S)&&getf2(id[u][v])==getf2(T)) return 0;
				if (getf2(id[x][y])==getf2(T)&&getf2(id[u][v])==getf2(S)) return 0;
			}
	}
	return 1;
}

int main(){
	n=IN(),m=IN(),q=IN();
	For(i,1,n+1){
		scanf("%s",s[i]+1);
	}
	if (s[1][1]=='#'||s[n][m]=='#'){
		For(i,0,q) puts("NO");
		return 0;
	}
	S=++tot,T=++tot;
	for (int i=2;i<=n;i++) id[i][0]=S,s[i][0]='#';
	for (int i=1;i<m;i++) id[n+1][i]=S,s[n+1][i]='#';
	for (int i=2;i<=m;i++) id[0][i]=T,s[0][i]='#';
	for (int i=1;i<n;i++) id[i][m+1]=T,s[i][m+1]='#';
	For(i,1,n+1) For(j,1,m+1) id[i][j]=++tot;
	For(i,1,tot+1) fa[i]=i;
	For(i,1,n+1) For(j,1,m+1)
		if (s[i][j]=='#'){
			For(k,0,8){
				int x=i+dx[k],y=j+dy[k];
				if (s[x][y]!='#') continue;
				Union(id[i][j],id[x][y]);
			}
		}
	For(i,1,n+1) For(j,1,m+1)
		if (s[i][j]=='.'){
			if (i==1&&j==1) continue;
			if (i==n&&j==m) continue;
			For(k,0,8){
				int x=i+dx[k],y=j+dy[k];
				if (s[x][y]!='#') continue;
				For(l,k+1,8){
					int u=i+dx[l],v=j+dy[l];
					if (s[u][v]!='#') continue;
					int a=getf(id[x][y]),b=getf(id[u][v]);
					if (a==b) continue;
					if (a>b) swap(a,b);
					M[a].insert(b);
				}
			}
		}
	For(i,1,tot+1) if (getf(i)==i) V[i].pb(i);
	For(i,1,q+1){
		res=Main(i);
		puts(res?"YES":"NO");
		fflush(stdout);
		For(j,0,tra.size()){
			s[tra[j].fi][tra[j].se]='.';
		}
		tra.clear();
		for (;top;top--){
			int x=stk[top];
			if (x>0) fa[x]=x;else V[-x].pop_back();
		}
	}
}