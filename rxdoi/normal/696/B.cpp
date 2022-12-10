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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=1e5+19;

struct Edge{
	int y,nxt;
} E[N];
db res[N];
int fa[N],las[N],sz[N];
int n,cnt;

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void dfs(int x){
	db tmp=0;
	for (int i=las[x],y;~i;i=E[i].nxt) tmp+=sz[y=E[i].y];
	for (int i=las[x],y;~i;i=E[i].nxt){
		y=E[i].y;
		res[y]=res[x]+(tmp-sz[y])/2+1;
		dfs(y);
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,2,n+1){
		fa[i]=IN();
		Add_Edge(fa[i],i);
	}
	for (int i=n;i;i--){
		sz[i]++;
		sz[fa[i]]+=sz[i];
	}
	res[1]=1;
	dfs(1);
	For(i,1,n+1) printf("%.10lf ",res[i]);
}