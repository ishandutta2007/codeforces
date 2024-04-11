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

const int N=100000+19;

struct Edge{
	int y,nxt;
} E[N*2];
Vi V[N];
int vis[N],Q[N],las[N];
int n,m,f,w,cnt;
Vi res;

void check(int x,int y){
	if (vis[x]==-1) vis[x]=y;
	lf (vis[x]!=y){
		puts("No");
		exit(0);
	}
}
void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,n+1){
		for (int k=IN();k--;) V[i].pb(IN());
	}
	For(i,1,n){
		int w=0;
		while (w<V[i].size()&&w<V[i+1].size()&&V[i][w]==V[i+1][w]) w++;
		if (w==V[i].size()&&w==V[i+1].size()) continue;
		if (w==V[i].size()) continue;
		if (w==V[i+1].size()) return puts("No"),0;
		if (V[i][w]<V[i+1][w]){
			Add_Edge(V[i+1][w],V[i][w]);
		}
	}
	memset(vis,-1,sizeof(vis));
	For(i,1,n){
		int w=0;
		while (w<V[i].size()&&w<V[i+1].size()&&V[i][w]==V[i+1][w]) w++;
		if (w==V[i].size()&&w==V[i+1].size()) continue;
		if (w==V[i].size()) continue;
		if (w==V[i+1].size()) return puts("No"),0;
		if (V[i][w]>V[i+1][w]){
			check(V[i][w],1);
			check(V[i+1][w],0);
		}
	}
	For(i,1,m+1) if (vis[i]==1) Q[++f]=i;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt){
			y=E[i].y;
			if (vis[y]==-1){
				vis[y]=1;
				Q[++f]=y;
			} lf (vis[y]==0){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	For(i,1,m+1) if (vis[i]==1) res.pb(i);
	printf("%d\n",res.size());
	For(i,0,res.size()) printf("%d ",res[i]);
	puts("");
}