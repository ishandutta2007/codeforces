#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x,f;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=4e6+19,W=1e5+19;
typedef long long LL;
struct Event
{
	int opt,x1,y1,x2,y2,v;
} E[W];
int n,m,w,L,R,x1,y1,x2,y2,Ql,Qr,v,tot;
LL Ans[W],Sum[N*4],Add[N*4];

//Seg
void Setadd(int x,int L,int R,LL v) {Add[x]+=v;Sum[x]+=1LL*v*(R-L+1);}
void Push_down(int x,int L,int R)
{
	if (L==R||!Add[x]) return;
	Setadd(Lsn,L,Mid,Add[x]);Setadd(Rsn,Mid+1,R,Add[x]);Add[x]=0;
}
void Update(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) {Setadd(x,L,R,v);return;}
	Push_down(x,L,R);
	if (Ql<=Mid) Update(Lsn,L,Mid);
	if (Qr>Mid) Update(Rsn,Mid+1,R);
	Sum[x]=Sum[Lsn]+Sum[Rsn];
}
LL Query(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) return Sum[x];
	Push_down(x,L,R);
	LL res=0;
	if (Ql<=Mid) res+=Query(Lsn,L,Mid);
	if (Qr>Mid) res+=Query(Rsn,Mid+1,R);
	return res;
}

int main()
{
	n=IN(),m=IN(),w=IN();
	For(i,0,w)
		if (IN()) E[i]=(Event){1,IN(),IN(),IN(),IN(),0};
			else E[i]=(Event){0,IN(),IN(),IN(),IN(),IN()};
	
	For(i,0,w)
	{
		Ql=E[i].y1,Qr=E[i].y2;
		if (E[i].opt) Ans[i]+=Query(1,1,m);
			else v=1LL*(E[i].x2-E[i].x1+1)*E[i].v,Update(1,1,m);
	}
	memset(Sum,0,sizeof(Sum));
	memset(Add,0,sizeof(Add));
	For(i,0,w)
		if (E[i].opt)
		{
			Ql=1,Qr=E[i].x1-1;if (Ql<=Qr) Ans[i]-=Query(1,1,n);
			Ql=E[i].x2+1,Qr=n;if (Ql<=Qr) Ans[i]-=Query(1,1,n);
		} else
		{
			v=1LL*(E[i].y2-E[i].y1+1)*E[i].v;
			Ql=E[i].x1,Qr=E[i].x2;if (Ql<=Qr) Update(1,1,n);
		}
	
	For(i,0,w) if (E[i].opt) printf("%I64d\n",Ans[i]);
}