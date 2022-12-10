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

const int N=100+3;
const int K=20+3;
const int p=1e9+7;

struct Edge{
	int y,nxt;
} E[N*2];
int f[N][K][2],g[K][2],las[N];
int n,k,cnt,res;

void U(int &x,ll y){
	x=(x+y)%p;
}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	f[x][k][0]=1;
	f[x][0][1]=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
			memset(g,0,sizeof(g));
			For(a,0,k+1)
				For(b,0,k+1){
					U(g[max(a,b-1)][0],1ll*f[x][a][0]*f[y][b][0]);
					U(g[max(a,b+1)][1],1ll*f[x][a][1]*f[y][b][1]);
					U(a>=b+1?g[a][0]:g[b+1][1],1ll*f[x][a][0]*f[y][b][1]);
					U(b-1>=a?g[b-1][0]:g[a][1],1ll*f[x][a][1]*f[y][b][0]);
				}
			For(a,0,k+1){
				f[x][a][0]=g[a][0];
				f[x][a][1]=g[a][1];
			}
		}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),k=IN();
	For(i,1,n) Link(IN(),IN());
	dfs(1,-1);
	For(i,0,k+1) U(res,f[1][i][0]);
	printf("%d\n",res);
}