#include<bits/stdc++.h>

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

const int N=200000+19;
const int M=100+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],dis[M][N],A[N];
int n,m,s,k,cnt; 

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void bfs(int s,int *dis){
	static int Q[N];
	int f=1,w=0;
	Q[1]=s;
	dis[s]=0;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[y=E[i].y]==-1){
				dis[y]=dis[x]+1;
				Q[++f]=y;
			}
	}
}

int main(){
	memset(dis,-1,sizeof(dis));
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),k=IN(),s=IN();
	For(i,1,n+1){
		A[i]=IN();
		Add_Edge(n+A[i],i);
	}
	For(i,1,m+1) Link(IN(),IN());
	For(i,1,k+1) bfs(i+n,dis[i]);
	For(i,1,n+1){
		Vi V;
		For(j,1,k+1) V.pb(dis[j][i]);
		sort(V.begin(),V.end());
		ll res=0;
		For(j,0,s) res+=V[j]-1;
		printf("%I64d ",res);
	}
	puts("");
}