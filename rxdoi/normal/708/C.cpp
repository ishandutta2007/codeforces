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
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if ((y=E[i].y)!=fa[x])
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

const int N=400000+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],fa[N],sz[N],mx[N],res[N],A[N],B[N];
int n,cnt;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs_1(int x){
	sz[x]=1;
	Rep(x){
		fa[y]=x;
		dfs_1(y);
		sz[x]+=sz[y];
		mx[x]=max(mx[x],sz[y]);
		A[x]=max(A[x],A[y]);
		if (sz[y]<=n/2) A[x]=max(A[x],sz[y]);
	}
	mx[x]=max(mx[x],n-sz[x]);
}
void dfs_2(int x,int tmp){
	int m1=0,m2=0;
	Rep(x){
		if (A[y]>A[m1]) m2=m1,m1=y;else
		if (A[y]>A[m2]) m2=y;
	}
	B[x]=tmp;
	Rep(x){
		int val=tmp;
		if (n-sz[y]<=n/2) val=max(val,n-sz[y]);
		if (y==m1){
			val=max(val,A[m2]);
			dfs_2(y,val);
		} else{
			val=max(val,A[m1]);
			dfs_2(y,val);
		}
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	dfs_1(1);
	For(x,1,n+1){
		if (mx[x]<=n/2) res[x]=1;
		Rep(x)
			if (sz[y]>n/2){
				if (sz[y]-A[y]<=n/2) res[x]=1;
			}
	}
	For(x,1,n+1){
		if (sz[x]<=n/2) A[x]=max(A[x],sz[x]);
	}
	dfs_2(1,0);
	For(x,1,n+1){
		if (n-sz[x]>n/2){
			if (n-sz[x]-B[x]<=n/2) res[x]=1;
		}
	}
	For(i,1,n+1){
		printf("%d ",res[i]);
	}
	puts("");
}