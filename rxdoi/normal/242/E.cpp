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
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
typedef long long LL;
int A[N],n,Ql,Qr,Q,x;
LL Ans;

struct Seg
{
	int Sum[N*4],Rev[N*4];
	
	void Setrev(int x,int L,int R) {Rev[x]^=1;Sum[x]=(R-L+1)-Sum[x];}
	void Push_down(int x,int L,int R)
	{
		if (L==R||!Rev[x]) return;
		Setrev(Lsn,L,Mid),Setrev(Rsn,Mid+1,R);Rev[x]=0;
	}
	void Build(int x,int L,int R)
	{
		if (L==R) {Sum[x]=A[L]&1;return;}
		Build(Lsn,L,Mid),Build(Rsn,Mid+1,R);
		Sum[x]=Sum[Lsn]+Sum[Rsn];
	}
	void Update(int x,int L,int R)
	{
		if (Ql<=L&&R<=Qr) {Setrev(x,L,R);return;}
		Push_down(x,L,R);
		if (Ql<=Mid) Update(Lsn,L,Mid);
		if (Qr>Mid) Update(Rsn,Mid+1,R);
		Sum[x]=Sum[Lsn]+Sum[Rsn];
	}
	int Query(int x,int L,int R)
	{
		if (Ql<=L&&R<=Qr) return Sum[x];
		Push_down(x,L,R);
		int tmp=0;
		if (Ql<=Mid) tmp+=Query(Lsn,L,Mid);
		if (Qr>Mid) tmp+=Query(Rsn,Mid+1,R);
		return tmp;
	}
} S[25];

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,0,25)
	{
		S[i].Build(1,1,n);
		For(j,1,n+1) A[j]>>=1;
	}
	for (Q=IN();Q--;)
		if (IN()==1)
		{
			Ql=IN(),Qr=IN(),Ans=0;
			For(i,0,25) Ans+=(1LL<<i)*S[i].Query(1,1,n);
			printf("%I64d\n",Ans);
		} else
		{
			Ql=IN(),Qr=IN(),x=IN();
			for (int i=0;i<25;i++,x>>=1) if (x&1) S[i].Update(1,1,n);
		}
}