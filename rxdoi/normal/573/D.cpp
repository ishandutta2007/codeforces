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
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

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

const int N=30000+19;
const ll oo=1ll<<59;

ll sum[N];
int A[N],B[N],x[N],y[N],alb[N],pos[N];
int n,m,u,v;

bool cmp1(int i,int j){
	return A[i]>A[j];
}
bool cmp2(int i,int j){
	return B[i]>B[j];
}

struct node{
	ll dp[3][3];
	int L,R;
	void Reset(int p){
		L=p,R=p;
		For(i,0,3) For(j,0,3) dp[i][j]=-oo;
		dp[0][1]=0;
		dp[1][0]=0;
		if (alb[x[p]]!=y[p]) dp[0][0]=1ll*A[x[p]]*B[y[p]];
	}
} seg[N*4];
int Qx,Qy;

ll cal(int x,int y){
	return alb[x]==y?-oo:1ll*A[x]*B[y];
}
void Upd(ll &x,ll y){
	if (y>x) x=y;
}

node Merge(const node &A,const node &B){
	static node C;
	C.L=A.L;
	C.R=B.R;
	For(a,0,3) For(d,0,3) C.dp[a][d]=-oo;
	//0/0
	For(a,0,3) For(d,0,3){
		Upd(C.dp[a][d],A.dp[a][0]+B.dp[0][d]);
	}
	//1/1
	For(a,0,3) For(d,0,3){
		Upd(C.dp[a][d],A.dp[a][1]+B.dp[1][d]+cal(x[A.R],y[B.L])+cal(x[B.L],y[A.R]));
	}
	//2/1
	For(a,0,3) For(d,0,3){
		Upd(C.dp[a][d],A.dp[a][2]+B.dp[1][d]+cal(x[A.R],y[B.L])+cal(x[A.R-1],y[A.R])+cal(x[B.L],y[A.R-1]));
		Upd(C.dp[a][d],A.dp[a][2]+B.dp[1][d]+cal(x[A.R],y[A.R-1])+cal(x[A.R-1],y[B.L])+cal(x[B.L],y[A.R]));
	}
	//1/2
	For(a,0,3) For(d,0,3){
		Upd(C.dp[a][d],A.dp[a][1]+B.dp[2][d]+cal(x[A.R],y[B.L])+cal(x[B.L],y[B.L+1])+cal(x[B.L+1],y[A.R]));
		Upd(C.dp[a][d],A.dp[a][1]+B.dp[2][d]+cal(x[A.R],y[B.L+1])+cal(x[B.L],y[A.R])+cal(x[B.L+1],y[B.L]));
	}
	if (B.L==B.R){
		C.dp[0][2]=A.dp[0][1];
		C.dp[1][2]=A.dp[1][1];
	}
	if (A.L==A.R){
		C.dp[2][0]=B.dp[1][0];
		C.dp[2][1]=B.dp[1][1];
	}
	return C;
}
void Build(int x,int L,int R){
	if (L==R){
		seg[x].Reset(L);
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	seg[x]=Merge(seg[Lsn],seg[Rsn]);
}
void Modify(int x,int L,int R){
	if (L==R){
		seg[x].Reset(L);
		return;
	}
	if (L<=Qx&&Qx<=Mid||L<=Qy&&Qy<=Mid) Modify(Lsn,L,Mid);
	if (Mid<Qx&&Qx<=R||Mid<Qy&&Qy<=R) Modify(Rsn,Mid+1,R);
	seg[x]=Merge(seg[Lsn],seg[Rsn]);
}

int main(){
	n=IN();m=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n+1) alb[i]=x[i]=y[i]=i;
	sort(x+1,x+n+1,cmp1);
	sort(y+1,y+n+1,cmp2);
	For(i,1,n+1){
		sum[i]=sum[i-1]+1ll*A[x[i]]*B[y[i]];
	}
	For(i,1,n+1) pos[x[i]]=i;
	Build(1,1,n);
	while (m--){
		u=IN(),v=IN();
		swap(alb[u],alb[v]);
		Qx=pos[u];Qy=pos[v];
		Modify(1,1,n);
		printf("%I64d\n",seg[1].dp[0][0]);
	}
}