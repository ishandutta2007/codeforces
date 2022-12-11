#include<cstdio>
#include<cctype>
#include<algorithm>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
using namespace std;

const int Maxn=3e5+19,Maxnote=1e6+19;
int A[Maxn],n,k,t,Ans,Min=(1<<30)-1,Max,nL,nR,cnt;

inline void Read(int &x)
{
	while (!isdigit(t=getchar()));
	x=t-'0';
	while (isdigit(t=getchar())) x=x*10+t-'0';
}
struct segment_tree
{
	int size[Maxnote<<2];
	
	inline void Update(int x,int L,int R,int v)
	{
		size[x]++;
		if (L==R) return;
		int Mid=(L+R)>>1;
		if (v<=Mid) Update(Lsn,L,Mid,v);else Update(Rsn,Mid+1,R,v);
	}
	inline void count(int x,int L,int R)
	{
		if (nL<=L&&R<=nR) {cnt+=size[x];return;}
		int Mid=(L+R)>>1;
		if (nL<=Mid) count(Lsn,L,Mid);
		if (nR>Mid) count(Rsn,Mid+1,R);
	}
	
} SegTree;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) 
	{
		Read(A[i]);
		Min=min(Min,A[i]);Max=max(Max,A[i]);
	}
	for (int i=1;i<=n;i++) SegTree.Update(1,Min,Max,A[i]);
	Ans=min(k+1,Min);
	for (int i=k+2;i<=Min;i++)
	{
		int tmp=0;
		for (int j=0;j*i<=Max;j++) 
		{
			nL=j*i,nR=min(j*i+k,Max),cnt=0;
			if (nR<Min) continue;
			SegTree.count(1,Min,Max);
			tmp+=cnt;
		}
		if (tmp==n) Ans=i;
	}
	printf("%d\n",Ans);
}