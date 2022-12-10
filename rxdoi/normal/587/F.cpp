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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;
const int S=315;

struct Edge{
	int y,nxt;
} E[N];

ll Ans[N];
int t[N][26],pt[N],Fail[N],las[N],I[N],O[N];
char s[N];
string str[N];
int num,n,m,l,r,k,x,cnt,dfn;

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void dfs(int x,int fa){
	I[x]=++dfn;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
		}
	O[x]=dfn;
}
void Build(){
	static int Q[N];
	int f=1,w=0;Q[1]=0;
	while (f>w){
		int x=Q[++w];
		if (x) Add_Edge(Fail[x],x);
		For(i,0,26){
			int &u=t[x][i];
			if (u){
				Q[++f]=u;
				if (x) Fail[u]=t[Fail[x]][i];
			} else u=t[Fail[x]][i];
		}
	}
}

namespace Big{
	struct QType{
		int l,r,id;
	};vector<QType> V[N];
	ll val[N],sum[N];
	void Ins(int l,int r,int k,int i){
		V[k].pb((QType){l,r,i});
	}
	void Main(){
		For(i,1,n+1)
			if (V[i].size()){
				memset(val,0,sizeof(val));
				x=0;
				For(j,0,str[i].length()){
					x=t[x][str[i][j]-'a'];
					val[I[x]]++;
				}
				For(j,1,dfn+1) val[j]+=val[j-1];
				For(j,1,n+1) sum[j]=val[O[pt[j]]]-val[I[pt[j]]-1];
				For(j,1,n+1) sum[j]+=sum[j-1];
				For(j,0,V[i].size()){
					Ans[V[i][j].id]=sum[V[i][j].r]-sum[V[i][j].l-1];
				}
			}
	}
}

namespace Sml{
	struct QType{
		int f,x,k,id;
		bool operator < (const QType &B) const {return x<B.x;}
	} Q[2*N];
	int plu[N],val[N];
	int Qc,c;
	void Add(int l,int r){
		for (;l<=r&&l%S!=0;l++) val[l]++;
		for (;l<=r&&r%S!=S-1;r--) val[r]++;
		if (l<=r){
			For(i,l/S,r/S+1) plu[i]++;
		}
	}
	int Qry(int x){
		return plu[x/S]+val[x];
	}
	void Ins(int l,int r,int k,int i){
		Q[++Qc]=(QType){1,r,k,i};
		Q[++Qc]=(QType){-1,l-1,k,i};
	}
	void Main(){
		sort(Q+1,Q+Qc+1);
		for (c=1;c<=Qc&&Q[c].x==0;c++);
		For(i,1,n+1){
			Add(I[pt[i]],O[pt[i]]);
			for (;c<=Qc&&Q[c].x==i;c++){
				x=0;
				For(j,0,str[Q[c].k].length()){
					x=t[x][str[Q[c].k][j]-'a'];
					Ans[Q[c].id]+=Q[c].f*Qry(I[x]);
				}
			}
		}
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();m=IN();
	For(w,1,n+1){
		scanf("%s",s+1);
		x=0;l=strlen(s+1);
		For(i,1,l+1){
			int &u=t[x][s[i]-'a'];
			if (!u) u=++num;x=u;
		}
		str[w]=string(s+1);
		pt[w]=x;
	}
	Build();
	dfs(0,-1);
	For(i,1,m+1){
		l=IN(),r=IN(),k=IN();
		if (str[k].length()>S){
			Big::Ins(l,r,k,i);
		} else{
			Sml::Ins(l,r,k,i);
		}
	}
	Big::Main();
	Sml::Main();
	For(i,1,m+1){
		printf("%I64d\n",Ans[i]);
	}
}