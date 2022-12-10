#include<set>
#include<map>
#include<ctime>
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
const int M=5000000;
const int oo=(1<<30)-1;

struct Edge{
	int y,f,nxt;
} E[M];
int las[N],Q[N],dis[N],I[N],O[N];
int S,T,s,t,cnt,num;

void Add_Edge(int x,int y,int l,int r){
	if (l>r){
		puts("-1");exit(0);
	}
	O[x]+=l,I[y]+=l;
	if (r-l){
		E[cnt]=(Edge){y,r-l,las[x]};las[x]=cnt++;
		E[cnt]=(Edge){x,0,las[y]};las[y]=cnt++;
	}
}
bool BFS(){
	For(i,1,num+1) dis[i]=-1;
	int f=1,w=0;
	Q[1]=S;dis[S]=1;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (E[i].f&&dis[y=E[i].y]==-1){
				dis[y]=dis[x]+1;
				Q[++f]=y;
				if (y==T) return 1;
			}
	}
	return 0;
}
int Dinic(int x,int flow){
	if (x==T||!flow) return flow;
	int res=0;
	for (int i=las[x],y;~i&&flow;i=E[i].nxt)
		if (E[i].f&&dis[y=E[i].y]==dis[x]+1){
			int tmp=Dinic(y,min(flow,E[i].f));
			E[i].f-=tmp,E[i^1].f+=tmp,flow-=tmp,res+=tmp;
		}
	if (!res) dis[x]=-1;
	return res;
}

typedef int one[N];
int n,m,r,b,chk,res;
one X,Y,x,y,cx,cy,idx,idy,o,v,d,mnx,mxx,mny,mxy,e;

int main(){
	memset(mxx,60,sizeof(mxx));
	memset(mxy,60,sizeof(mxy));
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	r=IN(),b=IN();
	if (r>b) swap(r,b),chk=1;
	For(i,1,n+1){
		x[i]=X[++*X]=IN();
		y[i]=Y[++*Y]=IN();
	}
	For(i,1,m+1){
		o[i]=IN(),v[i]=IN(),d[i]=IN();
	}
	sort(X+1,X+*X+1);*X=unique(X+1,X+*X+1)-X-1;
	sort(Y+1,Y+*Y+1);*Y=unique(Y+1,Y+*Y+1)-Y-1;
	For(i,1,*X+1) idx[i]=++num;
	For(i,1,*Y+1) idy[i]=++num;
	S=++num,T=++num,s=++num,t=++num;
	For(i,1,n+1){
		x[i]=lower_bound(X+1,X+*X+1,x[i])-X;
		y[i]=lower_bound(Y+1,Y+*Y+1,y[i])-Y;
		cx[x[i]]++,cy[y[i]]++;
		e[i]=cnt;
		Add_Edge(idx[x[i]],idy[y[i]],0,1);
	}
	For(i,1,m+1)
		if (o[i]==1){
			int tmp=lower_bound(X+1,X+*X+1,v[i])-X;
			if (tmp>*X||X[tmp]!=v[i]) continue;
			v[i]=tmp;
			mnx[v[i]]=max(mnx[v[i]],(cx[v[i]]-d[i]+1)/2);
			mxx[v[i]]=min(mxx[v[i]],(cx[v[i]]+d[i])/2);
		} else{
			int tmp=lower_bound(Y+1,Y+*Y+1,v[i])-Y;
			if (tmp>*Y||Y[tmp]!=v[i]) continue;
			v[i]=tmp;
			mny[v[i]]=max(mny[v[i]],(cy[v[i]]-d[i]+1)/2);
			mxy[v[i]]=min(mxy[v[i]],(cy[v[i]]+d[i])/2);
		}
	For(i,1,*X+1){
		mxx[i]=min(mxx[i],cx[i]);
		Add_Edge(s,idx[i],mnx[i],mxx[i]);
	}
	For(i,1,*Y+1){
		mxy[i]=min(mxy[i],cy[i]);
		Add_Edge(idy[i],t,mny[i],mxy[i]);
	}
	For(i,1,num+1)
		if (I[i]>O[i]){
			Add_Edge(S,i,0,I[i]-O[i]);
		} else{
			Add_Edge(i,T,0,O[i]-I[i]);
		}
	Add_Edge(t,s,0,(1<<30)-1);
	while (BFS()) Dinic(S,oo);
	for (int i=las[S];~i;i=E[i].nxt)
		if (E[i].f){
			puts("-1");
			return 0;
		}
	S=s,T=t;
	while (BFS()) res+=Dinic(S,oo);
	printf("%I64d\n",1ll*res*r+1ll*(n-res)*b);
	For(i,1,n+1){
		putchar("rb"[(E[e[i]].f!=0)^chk]);
	}
	puts("");
}