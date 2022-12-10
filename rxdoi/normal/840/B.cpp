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

const int N=300000+19;

struct Edge{
	int y,id,nxt;
} E[N*2];
int las[N],fa[N],bao[N],A[N];
int n,m,x,y,cnt;
Vi V,ans;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Link(int x,int y,int id){
	E[cnt]=(Edge){y,id,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,id,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if (E[i].id!=fa){
			y=E[i].y;
			dfs(y,E[i].id);
			bao[x]+=bao[y];
		}
	if (bao[x]&1){
		ans.pb(fa);
	} 
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,n+1) fa[i]=i;
	For(i,1,n+1){
		A[i]=IN();
		if (A[i]==1) V.pb(i); 
	}
	For(i,0,m){
		x=IN(),y=IN();
		if (getf(x)!=getf(y)){
			fa[getf(x)]=y;
			Link(x,y,i+1);
		}
	}
	if (V.size()&1){
		For(i,1,n+1) if (A[i]==-1) {V.pb(i);break;}
	}
	if (V.size()&1){
		puts("-1");
		return 0;
	}
	For(i,0,V.size()) bao[V[i]]=1;
	dfs(1,-1);
	printf("%d\n",ans.size());
	For(i,0,ans.size()) printf("%d ",ans[i]);
	puts("");
}