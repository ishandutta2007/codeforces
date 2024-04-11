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

const int N=3e5+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],pre[N],Q[N],dis[N],vis[N],wei[N];
int n,m,cnt,tmp,f,w,T;
map<pii,int> M;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
	M[mp(x,y)]=M[mp(y,x)]=1;
}
void bfs1(){
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	int f=1,w=0;Q[1]=1;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[y=E[i].y]==-1){
				dis[y]=dis[x]+1;
				Q[++f]=y;
				pre[y]=x;
			}
	}
	tmp=dis[n];
}
void gao4(){
	For(x,2,n+1) if (dis[x]==2){
		puts("4");
		printf("1 %d %d %d %d\n",pre[x],x,1,n);
		exit(0);
	}
}
void gao5(int s){
	int f=1,w=0,num=0;
	Q[1]=s;wei[s]=1;
	while (f>w){
		int x=Q[++w];
		if (s!=x&&!M.count(mp(s,x))){
			puts("5");
			printf("1 %d %d %d %d %d\n",s,pre[x],x,s,n);
			exit(0);
		}
		for (int i=las[x],y;~i;i=E[i].nxt)
			if ((y=E[i].y)!=1){
				num++;
				if (!wei[y]){
					wei[y]=1;
					pre[y]=x;
					Q[++f]=y;
				}
			}
	}
	if (f>=3&&num!=f*(f-1)){
		puts("5");
		For(i,2,f+1) For(j,i+1,f+1)
			if (!M.count(mp(Q[i],Q[j]))){
				printf("1 %d %d %d %d %d\n",Q[i],s,Q[j],Q[i],n);
				exit(0);
			}
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,0,m) Link(IN(),IN());
	bfs1();
	if (tmp!=-1&&tmp<=4){
		Vi V;
		for (int i=n;i;i=pre[i]) V.pb(i);
		reverse(V.begin(),V.end());
		printf("%d\n",V.size()-1);
		For(i,0,V.size()) printf("%d ",V[i]);
		puts("");
		exit(0);
	}
	gao4();
	For(i,1,n+1) if (dis[i]==1&&!wei[i]) gao5(i);
	puts("-1");
}