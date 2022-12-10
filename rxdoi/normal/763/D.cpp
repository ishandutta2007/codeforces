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

const int N=1e5+19;
const int p=1e9+7;

struct Edge{
	int y,nxt;
} E[N*2];
map<pii,int> M;
map<int,int> C;
int las[N];
int n,cnt,mx,res,num;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
int F(int x,int fa){
	if (M.count(mp(x,fa))) return M[mp(x,fa)];
	int res=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			int tmp=F(y,x);
			res=(res+1ll*tmp*tmp%p*tmp)%p;
		}
	return M[mp(x,fa)]=res;
}
void dfs(int x,int fa){
	int tmp=F(x,fa);
	if (++C[tmp]==1) num++;
	if (x!=1){
		tmp=(tmp+1ll*F(fa,x)*F(fa,x)%p*F(fa,x))%p;
	}
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			int val=(tmp-1ll*F(y,x)*F(y,x)%p*F(y,x)%p+p)%p;
			M[mp(x,y)]=val;
			dfs(y,x);
		}
}
void Dfs(int x,int fa){
	if (num>mx) mx=num,res=x;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			if (++C[F(x,y)]==1) num++;
			if (--C[F(y,x)]==0) num--;
			Dfs(y,x);
			if (++C[F(y,x)]==1) num++;
			if (--C[F(x,y)]==0) num--;
		}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	F(1,-1);
	dfs(1,-1);
	Dfs(1,-1);
	printf("%d\n",res);
}