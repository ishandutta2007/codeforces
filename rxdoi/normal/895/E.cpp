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
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)

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

db sum[N*4],mul[N*4],plu[N*4],ans,s1,s2,a,b;
int n,q,l1,r1,l2,r2,l,r,Ql,Qr;

void Build(int x,int L,int R){
	mul[x]=1;
	plu[x]=0;
	if (L==R){
		sum[x]=IN();
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]+sum[Rsn];
}
void Mul(int x,db v){
	mul[x]*=v;
	plu[x]*=v;
	sum[x]*=v;
}
void Plus(int x,int L,int R,db v){
	plu[x]+=v;
	sum[x]+=v*(R-L+1);
}
void Down(int x,int L,int R){
	if (mul[x]!=1){
		Mul(Lsn,mul[x]);
		Mul(Rsn,mul[x]);
		mul[x]=1;
	}
	if (plu[x]!=0){
		Plus(Lsn,L,Mid,plu[x]);
		Plus(Rsn,Mid+1,R,plu[x]);
		plu[x]=0;
	}
}
db Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return sum[x];
	Down(x,L,R);
	if (Qr<=Mid) return Query(Lsn,L,Mid);
	if (Ql>Mid) return Query(Rsn,Mid+1,R);
	return Query(Lsn,L,Mid)+Query(Rsn,Mid+1,R);
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Mul(x,a);
		Plus(x,L,R,b);
		return;
	}
	Down(x,L,R);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]+sum[Rsn];
}

int main(){
	n=IN(),q=IN();
	Build(1,1,n);
	while (q--){
		if (IN()==1){
			l1=IN(),r1=IN(),l2=IN(),r2=IN();
			Ql=l1,Qr=r1;s1=Query(1,1,n);
			Ql=l2,Qr=r2;s2=Query(1,1,n);
			a=1.0*(r1-l1)/(r1-l1+1),b=s2/(r2-l2+1)/(r1-l1+1);
			Ql=l1,Qr=r1;Modify(1,1,n);
			a=1.0*(r2-l2)/(r2-l2+1),b=s1/(r1-l1+1)/(r2-l2+1);
			Ql=l2,Qr=r2;Modify(1,1,n);
		} else{
			Ql=IN(),Qr=IN();
			printf("%.10lf\n",Query(1,1,n));
		}
	}
}