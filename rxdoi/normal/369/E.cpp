#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=3e5+19,Len=1e6+19;
struct Seg {int L,R,ID;} A[Maxn*3];
int n,m,l,r,cnt,t;
int s[Maxn],Ans[Maxn],c[Len];

inline int cmp(Seg A,Seg B) {return A.L>B.L||A.L==B.L&&A.ID<B.ID;}
inline void Add(int x) {while (x<=1e6) c[x]++,x+=x&-x;}
inline int Query(int x) {int Ans=0;while (x) Ans+=c[x],x-=x&-x;return Ans;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i].L,&A[i].R),A[i].ID=0;
	cnt=n;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		for (int j=1;j<=t;j++) scanf("%d",&s[j]);
		s[0]=0;s[t+1]=1e6+1;
		for (int j=0;j<=t;j++)
			if (s[j]+1<=s[j+1]-1) A[++cnt]=(Seg){s[j]+1,s[j+1]-1,i};
	}
	sort(A+1,A+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
		if (A[i].ID==0) Add(A[i].R);else Ans[A[i].ID]+=Query(A[i].R);
	for (int i=1;i<=m;i++) printf("%d\n",n-Ans[i]);
}