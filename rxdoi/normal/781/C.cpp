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

const int N=200000+19;

struct Edge{
	int y,nxt;
} E[N*2];
Vi V,T;
int las[N],fa[N];
int n,cnt,m,k,x,y,now,top;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y;
}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	V.pb(x);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			V.pb(x);
		}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();m=IN();k=IN();
	top=2*n%k==0?2*n/k:(2*n/k+1);
	For(i,1,n+1) fa[i]=i;
	For(i,1,m+1){
		x=IN(),y=IN();
		if (getf(x)!=getf(y)){
			Union(x,y);
			Link(x,y);
		}
	}
	dfs(1,-1);
	now=0;
	For(i,0,k){
		T.clear();
		while (now<V.size()&&T.size()<top) T.pb(V[now++]);
		if (T.empty()){
			puts("1 1");
		} else{
			printf("%d\n",T.size());
			For(j,0,T.size()) printf("%d ",T[j]);
			puts("");
		}
	}
}