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
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)

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

const int N=100000+19;
const ll oo=1ll<<60;

struct Edge{
	int y,nxt;
} E[N*2];
vector<pii> V[N];
int las[N],I[N],O[N],fa[N],sz[N],top[N],dep[N],son[N],c[N];
int n,m,Qc,cnt,tot,k,x,y;
Vi res;

ll plu[N*4];
pair<ll,int> mn[N*4];
int Qx,Ql,Qr,Qv;

void Plus(int x,ll v){
	mn[x].fi+=v;plu[x]+=v;
}
void Down(int x){
	if (plu[x]){
		Plus(Lsn,plu[x]);
		Plus(Rsn,plu[x]);
		plu[x]=0;
	}
}
void Build(int x,int L,int R){
	if (L==R){
		if (V[L].empty()){
			mn[x]=mp(oo,0);
		} else{
			mn[x]=mp(V[L].back().fi,L);
		}
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
}
void Erase(int x,int L,int R){
	if (L==R){
		V[L].pop_back();
		if (V[L].empty()){
			mn[x]=mp(oo,0);
		} else{
			mn[x]=mp(V[L].back().fi+plu[x],L);
		}
		return;
	}
	Down(x);
	Qx<=Mid?Erase(Lsn,L,Mid):Erase(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Plus(x,Qv);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
}
pair<ll,int> Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return mn[x];
	Down(x);
	pair<ll,int> res=mp(oo,0);
	if (Ql<=Mid) res=min(res,Query(Lsn,L,Mid));
	if (Qr>Mid) res=min(res,Query(Rsn,Mid+1,R));
	return res;
}

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x){
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
void dfs(int x,int Anc){
	I[x]=++tot;top[x]=Anc;
	if (son[x]) dfs(son[x],Anc);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
	O[x]=tot;
}
pair<ll,int> Query(int x,int y){
	int a=top[x],b=top[y];
	pair<ll,int> res=mp(oo,0);
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		Ql=I[b],Qr=I[y];
		res=min(res,Query(1,1,n));
		y=fa[b],b=top[y];
	}
	Ql=I[x],Qr=I[y];
	if (Ql>Qr) swap(Ql,Qr);
	res=min(res,Query(1,1,n));
	return res;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();m=IN();Qc=IN();
	For(i,1,n) Link(IN(),IN());
	For(i,1,m+1) c[i]=IN();
	dfs(1);
	dfs(1,1);
	For(i,1,m+1) V[I[c[i]]].pb(mp(i,i));
	For(i,1,n+1){
		sort(V[i].begin(),V[i].end());
		reverse(V[i].begin(),V[i].end());
	}
	Build(1,1,n);
	while (Qc--){
		if (IN()==1){
			x=IN(),y=IN(),k=IN();
			res.clear();
			for (;k;k--){
				pair<ll,int> tmp=Query(x,y);
				if (tmp.se==0) break;
				res.pb(V[tmp.se].back().se);
				Qx=tmp.se;
				Erase(1,1,n);
			}
			printf("%d ",res.size());
			For(i,0,res.size()) printf("%d ",res[i]);
			puts("");
		} else{
			x=IN(),Qv=IN();
			Ql=I[x],Qr=O[x];
			Modify(1,1,n);
		}
	}
}