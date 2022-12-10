#include<bits/stdc++.h>

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
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;
const ll oo=1ll<<60;

struct info{
	int u,v,w;
	bool operator < (const info &B) const{
		return u<B.u;
	}
} P[N];
ll F[N],B[N];
int A[N];
int n,m,q,x,w,c;

ll mn[N*4],plu[N*4],mn2[N*4];
int Ql,Qr,Qv,Qx;

void Plus(int x,ll v){
	plu[x]+=v;
	mn[x]+=v;
}
void Down(int x){
	if (plu[x]){
		Plus(Lsn,plu[x]);
		Plus(Rsn,plu[x]);
		plu[x]=0;
	}
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Plus(x,Qv);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
}
void Build(int x,int L,int R){
	if (L==R){
		mn[x]=B[L];
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
}
void Build2(int x,int L,int R){
	if (L==R){
		mn2[x]=F[L]+A[L];
		return;
	}
	Build2(Lsn,L,Mid);
	Build2(Rsn,Mid+1,R);
	mn2[x]=min(mn2[Lsn],mn2[Rsn]);
}
void Modify2(int x,int L,int R){
	if (L==R){
		mn2[x]=F[L]+A[L];
		return;
	}
	Qx<=Mid?Modify2(Lsn,L,Mid):Modify2(Rsn,Mid+1,R);
	mn2[x]=min(mn2[Lsn],mn2[Rsn]);
}

int main(){
	n=IN(),m=IN(),q=IN();
	For(i,1,n){
		A[i]=IN(),B[i]=IN();
	}
	For(i,0,m) P[i]=(info){IN(),IN(),IN()};
	sort(P,P+m);
	Build(1,0,n-1);
	For(i,1,n+1){
		F[i]=oo;
		for (;c<m&&P[c].u<=i;c++){
			Ql=0,Qr=P[c].v-1,Qv=P[c].w;
			Modify(1,0,n-1);
//			For(j,0,P[c].v) B[j]+=P[c].w;
		}
		F[i]=mn[1];
//		For(j,0,n) F[i]=min(F[i],B[j]);
	}
	Build2(1,1,n);
	printf("%I64d\n",mn2[1]);
	while (q--){
		x=IN(),w=IN();
		A[x]=w;
		Qx=x;
		Modify2(1,1,n);
		printf("%I64d\n",mn2[1]);
	}
}