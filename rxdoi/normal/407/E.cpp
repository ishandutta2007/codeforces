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

const int N=200000+19;
const int top=1e9;

int A[N],B[N];
int n,k,d,L,R=-1;

ll mn[N*4],plu[N*4];
int Ql,Qr,Qx,ans;
ll Qv;

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
int Query2(int x,int L,int R){
	if (L==R) return L;
	Down(x);
	return mn[Lsn]<=Qv?Query2(Lsn,L,Mid):Query2(Rsn,Mid+1,R);
}
void Query(int x,int L,int R){
	if (ans) return;
	if (Ql<=L&&R<=Qr){
		if (mn[x]<=Qv) ans=Query2(x,L,R);
		return;
	}
	Down(x);
	if (Ql<=Mid) Query(Lsn,L,Mid);
	if (Qr>Mid) Query(Rsn,Mid+1,R);
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
void Renew(int x,int L,int R){
	if (L==R){
		mn[x]=L;
		return;
	}
	Down(x);
	Qx<=Mid?Renew(Lsn,L,Mid):Renew(Rsn,Mid+1,R);
	mn[x]=min(mn[Lsn],mn[Rsn]);
}

void Work(int le){
	static int stk1[N],stk2[N];
	int top1,top2,tmp;
	map<int,int> las;
	stk1[top1=1]=0;
	stk2[top2=1]=0;
	tmp=0;
	For(i,1,*B+1){
		for (;top1>=2&&B[i]>=B[stk1[top1]];top1--){
			Ql=stk1[top1-1]+1;
			Qr=stk1[top1];
			Qv=B[i]-B[stk1[top1]];
			Modify(1,1,*B);
		}
		stk1[++top1]=i;
		for (;top2>=2&&B[i]<=B[stk2[top2]];top2--){
			Ql=stk2[top2-1]+1;
			Qr=stk2[top2];
			Qv=B[stk2[top2]]-B[i];
			Modify(1,1,*B);
		}
		stk2[++top2]=i;
		Qx=i;
		Renew(1,1,*B);
		Ql=tmp=max(tmp,las[B[i]]+1);
		Qr=i;
		Qv=i+k;
		ans=0;
		Query(1,1,*B);
		if (ans&&i-ans+1>R-L+1){
			L=ans+le-1,R=i+le-1;
		}
		las[B[i]]=i;
	}
}

int main(){
	n=IN(),k=IN(),d=IN();
	For(i,1,n+1) A[i]=IN()+top;
	if (d==0){
		for (int l=1,r;l<=n;l=r+1){
			for (r=l;r+1<=n&&A[r+1]==A[l];r++);
			if (r-l+1>R-L+1){
				L=l,R=r;
			}
		}
	} else{
		for (int l=1,r;l<=n;l=r+1){
			for (r=l;r+1<=n&&A[r+1]%d==A[l]%d;r++);
			if (r-l+1>R-L+1){
				*B=0;
				For(i,l,r+1) B[++*B]=A[i]/d;
				Work(l);
			}
		}
	}
	printf("%d %d\n",L,R);
}