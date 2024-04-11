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

const int N=2e5+19;
const int p=1e9+7;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],dis[N],vis[N],A[N];
int cnt,n,x,res,sum;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	vis[x]=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if (i!=fa)
			if (!vis[y=E[i].y]){
				dis[y]=dis[x]+1;
				dfs(y,i^1);
			} else if (dis[y]<dis[x]){
				A[++*A]=dis[x]-dis[y]+1;
			}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n+1) Link(i,IN());
	For(i,1,n+1) if (!vis[i]) dfs(i,-1);
	res=1;
	For(i,1,*A+1){
		res=1ll*res*(Pow(2,A[i])-2+p)%p;
		sum+=A[i];
	}
	res=1ll*res*Pow(2,n-sum)%p;
	printf("%d\n",res);
}