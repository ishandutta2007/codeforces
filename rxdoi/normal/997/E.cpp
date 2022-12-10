#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=120000+19;

ll ans[N*4],res[N];
int mn[N*4],cnt[N*4],plu[N*4],plu2[N*4];
int Ql,Qr,Qv;
int A[N],stk1[N],stk2[N];
int n,top1,top2,q,l,r;
vector<pii> V[N];

void Plus1(int x,int v){
	mn[x]+=v;
	plu[x]+=v;
}
void Plus2(int x,int v){
	plu2[x]+=v;
	ans[x]+=1ll*v*cnt[x];
}
void Down(int x){
	if (plu[x]){
		Plus1(Lsn,plu[x]);
		Plus1(Rsn,plu[x]);
		plu[x]=0;
	}
	if (plu2[x]){
		if (mn[Lsn]==mn[x]) Plus2(Lsn,plu2[x]);
		if (mn[Rsn]==mn[x]) Plus2(Rsn,plu2[x]);
		plu2[x]=0;
	}
}
void Update(int x){
	mn[x]=min(mn[Lsn],mn[Rsn]);
	cnt[x]=0;
	if (mn[Lsn]==mn[x]) cnt[x]+=cnt[Lsn];
	if (mn[Rsn]==mn[x]) cnt[x]+=cnt[Rsn];
	ans[x]=ans[Lsn]+ans[Rsn];
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Plus1(x,Qv);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	Update(x);
}
ll Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return ans[x];
	Down(x);
	ll res=0;
	if (Ql<=Mid) res+=Query(Lsn,L,Mid);
	if (Qr>Mid) res+=Query(Rsn,Mid+1,R);
	return res;
}
void Build(int x,int L,int R){
	mn[x]=L;
	cnt[x]=1;
	if (L==R) return;
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	Build(1,1,n);
	q=IN();
	For(i,1,q+1){
		l=IN(),r=IN();
		V[r].pb(mp(l,i));
	}
	For(i,1,n+1){
		for (;top1>0&&A[i]>A[stk1[top1]];top1--){
			Ql=stk1[top1-1]+1;
			Qr=stk1[top1];
			Qv=A[i]-A[stk1[top1]];
			Modify(1,1,n);
		}
		stk1[++top1]=i;
		for (;top2>0&&A[i]<A[stk2[top2]];top2--){
			Ql=stk2[top2-1]+1;
			Qr=stk2[top2];
			Qv=A[stk2[top2]]-A[i];
			Modify(1,1,n);
		}
		stk2[++top2]=i;
		Plus1(1,-1);
		Plus2(1,1);
		for (pii Q:V[i]){
			Ql=Q.fi;
			Qr=i;
			res[Q.se]=Query(1,1,n);
		}
	}
	For(i,1,q+1){
		printf("%lld\n",res[i]);
	}
}