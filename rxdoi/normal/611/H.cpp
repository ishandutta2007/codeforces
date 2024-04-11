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
#define fir first
#define sec second

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

const int N=200000+19,M=5000000,oo=(1<<30)-1;

typedef int one[N];
one Last,Q,dis;

struct edge{
	int x,y;
} e[N],r[N];
struct Edge{
	int y,f,nxt;
} E[M];
int c[20][20],num[20],id[20][20],vis[20];
int S,T,cnt,n,tot,top;
int pow10[]={1,10,100,1000,10000,100000,1000000};
char s[20],t[20];

inline int len(int x){
	int res=0;
	while (x) x/=10,res++;
	return res;
}

void Add_Edge(int x,int y,int f){
	E[cnt]=(Edge){y,f,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,0,Last[y]};Last[y]=cnt++;
}
bool bfs(){
	memset(dis,-1,sizeof(dis));
	dis[S]=1;
	int f=1,w=0;Q[1]=S;
	while (f>w){
		int x=Q[++w];
		for (int i=Last[x],y;~i;i=E[i].nxt)
			if (E[i].f&&dis[y=E[i].y]==-1) dis[y]=dis[x]+1,Q[++f]=y;
	}
	return dis[T]!=-1;
}
int dinic(int x,int flow){
	if (x==T||!flow) return flow;
	int res=0;
	for (int i=Last[x],y;~i;i=E[i].nxt)
		if (E[i].f&&dis[y=E[i].y]==dis[x]+1){
			int tmp=dinic(y,min(flow,E[i].f));
			E[i].f-=tmp,E[i^1].f+=tmp,flow-=tmp,res+=tmp;
		}
	if (!res) dis[x]=-1;
	return res;
}

void output(){
	vector<pii> V[7][7];
	For(i,0,tot){
		int x=e[i].x,y=e[i].y;
		if (x>y) swap(x,y);
		V[len(x)][len(y)].pb(mp(x,y));
	}
	For(i,1,n){
		int x=r[i].x,y=r[i].y;
		pii P=V[min(x,y)][max(x,y)].back();
		if (x>y) swap(P.fir,P.sec);
		printf("%d %d\n",P.fir,P.sec);
		V[min(x,y)][max(x,y)].pop_back();
	}
}
void work(){
	int __id=top;
	memset(Last,-1,sizeof(Last));
	S=top*top+top+1,T=S+1;cnt=0;
	For(i,1,top+1)
		For(j,i,top+1){
			id[i][j]=++__id;
			Add_Edge(__id,T,c[i][j]);
			Add_Edge(i,__id,oo);
			Add_Edge(j,__id,oo);
		}
	For(i,1,top+1){
		Add_Edge(S,i,num[i]-1);
	}
	int res=0;
	while (bfs()) res+=dinic(S,oo);
	if (res==n-top){
		For(x,1,top+1){
			int w=pow10[x-1];
			For(j,1,top+1){
				for (int i=Last[x];~i;i=E[i].nxt)
					if (E[i].y==id[x][j])
						while (E[i^1].f>0) e[tot++]=(edge){++w,pow10[j-1]},E[i^1].f--;
			}
			For(j,1,top+1){
				for (int i=Last[x];~i;i=E[i].nxt)
					if (E[i].y==id[j][x])
						while (E[i^1].f>0) e[tot++]=(edge){++w,pow10[j-1]},E[i^1].f--;
			}
		}
		output();
		exit(0);
	}
}
void dfs(int d){
	if (d>top){
		work();
		return;
	}
	For(i,1,top+1) if (!vis[i]){
		vis[i]=1;
		For(j,1,top+1) if (i!=j&&vis[j]&&c[min(i,j)][max(i,j)]){
			c[min(i,j)][max(i,j)]--;
			e[tot++]=(edge){pow10[i-1],pow10[j-1]};
			dfs(d+1);
			c[min(i,j)][max(i,j)]++;
		}
		vis[i]=0;
	}
}

int main(){
	n=IN();
	top=len(n);
	For(i,1,n+1) num[len(i)]++;
	For(i,1,n){
		scanf("%s%s",s,t);
		int ls=strlen(s),lt=strlen(t);
		c[min(ls,lt)][max(ls,lt)]++;
		r[i]=(edge){ls,lt};
	}
	vis[1]=1;
	dfs(2);
	puts("-1");
}