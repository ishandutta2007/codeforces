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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

struct Edge{
	int y,nxt;
};
struct Tree{
	Edge E[N*2];
	int las[N],cnt;
	Tree(){
		memset(las,-1,sizeof(las));
	}
	void Link(int x,int y){
		E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
		E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
	}
} S,T;

Vi V[N];
int f[N][13],g[1<<13],son[13];
int n,m,res,c;

void Upd(int &x,ll y){
	x=(x+y)%p;
}
void dfs(int x,int fa){
	for (int i=T.las[x],y;~i;i=T.E[i].nxt)
		if ((y=T.E[i].y)!=fa){
			V[x].pb(y);
			son[x]|=1<<y-1;
			dfs(y,x);
		}
}
void dp(Tree &S,int x,int fa){
	for (int i=S.las[x],y;~i;i=S.E[i].nxt)
		if ((y=S.E[i].y)!=fa){
			dp(S,y,x);
		}
	memset(g,0,sizeof(g));
	g[0]=1;
	for (int i=S.las[x],y;~i;i=S.E[i].nxt)
		if ((y=S.E[i].y)!=fa){
			for (int t=(1<<m)-1;~t;t--) if (g[t])
				For(z,1,m+1) if (f[y][z]&&!(t>>z-1&1)){
					Upd(g[t|1<<z-1],1ll*g[t]*f[y][z]);
				}
		}
	For(i,1,m+1){
		f[x][i]=g[son[i]];
	}
}
int Work(Tree &S){
	int res=0;
	For(i,1,m+1){
		memset(son,0,sizeof(son));
		memset(f,0,sizeof(f));
		For(j,1,m+1) V[j].clear();
		dfs(i,-1);
		dp(S,1,-1);
		For(j,1,n+1) res=(res+f[j][i])%p;
	}
	return res;
}

int main(){
	n=IN();
	For(i,1,n) S.Link(IN(),IN());
	m=IN();
	For(i,1,m) T.Link(IN(),IN());
	res=Work(S);
	res=1ll*res*Pow(Work(T),p-2)%p;
	printf("%d\n",res);
}