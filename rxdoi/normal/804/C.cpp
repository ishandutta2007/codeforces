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

const int N=300000+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],vis[N],col[N];
int n,cnt,Time,mx,m;
Vi V[N];

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	Time++;
	for (int i:V[x]){
		if (col[i]) vis[col[i]]=Time;
	}
	int c=1;
	for (int i:V[x])
		if (!col[i]){
			while (vis[c]==Time) c++;
			col[i]=c++;
		}
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
		}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,n+1){
		for (int t=IN();t--;) V[i].pb(IN());
	}
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	For(i,1,m+1){
		if (!col[i]) col[i]=1;
	}
	For(i,1,m+1) mx=max(mx,col[i]);
	printf("%d\n",mx);
	For(i,1,m+1) printf("%d ",col[i]);
	puts("");
}