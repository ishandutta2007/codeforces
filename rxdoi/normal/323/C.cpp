#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e6+19,Top=40000000;
int A[N],B[N],D[N],n,Q;

struct node
{
	node *L,*R;
	int S;
} Nd[Top],*cur=Nd,*rt[N],*null;
int Qx,Ql,Qr,L,R,Ans;

node *New(node *L,node *R,int S) {return *cur=(node){L,R,S},cur++;}
void Insert(node *&x,node *y,int L,int R)
{
	x=New(y->L,y->R,y->S+1);
	if (L==R) return;
	Qx<=Mid?Insert(x->L,y->L,L,Mid):Insert(x->R,y->R,Mid+1,R);
}
int Query(node *x,int L,int R)
{
	if (x==null||Ql<=L&&R<=Qr) return x->S;
	int res=0;
	if (Ql<=Mid) res+=Query(x->L,L,Mid);
	if (Qr>Mid) res+=Query(x->R,Mid+1,R);
	return res;
}

int main()
{
	rt[0]=null=New(Nd,Nd,0);
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) D[B[i]=IN()]=i;
	For(i,1,n+1) Qx=D[A[i]],Insert(rt[i],rt[i-1],1,n);
	for (Q=IN();Q--;)
	{
		L=(IN()+Ans-1)%n+1,R=(IN()+Ans-1)%n+1;Ql=(IN()+Ans-1)%n+1,Qr=(IN()+Ans-1)%n+1;
		if (L>R) swap(L,R);
		if (Ql>Qr) swap(Ql,Qr);
		printf("%d\n",Ans=Query(rt[R],1,n)-Query(rt[L-1],1,n));Ans++;
	}
}