#include<cstdio>
#include<cctype>
#include<cassert>
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

const int N=2000000+19;

int res[N],fa[N],c[N],r[N],rx[N],cx[N],rv[N],cv[N],key[N];
int n,m,pre=1,Time,x,y;

struct node{
	int x,y,v;
	bool operator < (const node &B) const {return v<B.v;}
} A[N];

#define ID(x,y) ((x-1)*m+y)
//int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
int getf(int x){
	if (fa[x]==x) return x;
	static int S[N];*S=0;
	while (fa[x]!=x) S[++*S]=x,x=fa[x];S[++*S]=x;
	For(i,1,*S) fa[S[i]]=S[*S];
	return S[*S];
}
void Work(int L,int R){
	For(i,L,R+1) fa[i]=i;
	Time++;
	For(i,L,R+1){
		x=A[i].x,y=A[i].y;
		if (r[x]!=Time) r[x]=Time,rx[x]=i;else fa[getf(i)]=getf(rx[x]);
		if (c[y]!=Time) c[y]=Time,cx[y]=i;else fa[getf(i)]=getf(cx[y]);
	}
	For(i,L,R+1){
		x=A[i].x,y=A[i].y;
		key[getf(i)]=max(key[getf(i)],max(rv[x],cv[y])+1);
	}
	For(i,L,R+1){
		x=A[i].x,y=A[i].y;
		int v=key[getf(i)];
		rv[x]=max(rv[x],v);
		cv[y]=max(cv[y],v);
		res[ID(x,y)]=v;
	}
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1){
		For(j,1,m+1){
			A[ID(i,j)]=(node){i,j,IN()};
		}
	}
	sort(A+1,A+n*m+1);
	For(i,1,n*m+2)
		if (i>n*m||A[i].v!=A[pre].v) Work(pre,i-1),pre=i;
	For(i,1,n+1){
		For(j,1,m+1) printf("%d ",res[ID(i,j)]);
		puts("");
	}
}