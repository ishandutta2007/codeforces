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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;
const ll oo=1ll<<60;

ll M(ll x,ll y){
	return 1.0*x*y>oo?oo:x*y;
}

ll mul[N*4],Qv;
int Ql,Qr,Qx;

ll Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return mul[x];
	ll res=1;
	if (Ql<=Mid) res=M(res,Query(Lsn,L,Mid));
	if (Qr>Mid) res=M(res,Query(Rsn,Mid+1,R));
	return res;
}
void Modify(int x,int L,int R){
	if (L==R){
		mul[x]=Qv;return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
	mul[x]=M(mul[Lsn],mul[Rsn]);
}

struct Edge{
	int y;ll z;int id,nxt;
} E[N*2];
typedef int one[N];
one las,fa,sz,top,id,son,dep,pos,e;
int n,cnt,Qc,x,y,tot;
ll z;

void Link(int x,int y,ll z,int id){
	E[cnt]=(Edge){y,z,id,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,id,las[y]};las[y]=cnt++;
}
void dfs(int x){
	sz[x]=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			e[y]=i;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
		}
}
void dfs(int x,int Anc){
	id[x]=++tot,top[x]=Anc;
	if (x>1){
		Qx=tot;Qv=E[e[x]].z;
		Modify(1,1,n);
		pos[E[e[x]].id]=tot;
	}
	if (son[x]) dfs(son[x],Anc);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
}
void Query(int x,int y){
	int a=top[x],b=top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		Ql=id[b],Qr=id[y];
		z/=Query(1,1,n);
		y=fa[b],b=top[y];
	}
	Ql=id[x],Qr=id[y];
	if (Ql>Qr) swap(Ql,Qr);
	if (++Ql<=Qr) z/=Query(1,1,n);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),Qc=IN();
	For(i,1,n){
		x=IN(),y=IN(),z=IN();
		Link(x,y,z,i);
	}
	dfs(1);
	dfs(1,1);
	while (Qc--){
		if (IN()==1){
			x=IN(),y=IN(),z=IN();
			Query(x,y);
			printf("%I64d\n",z);
		} else{
			Qx=pos[IN()];Qv=IN();
			Modify(1,1,n);
		}
	}
}