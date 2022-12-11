#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=2000+19;
typedef long long LL;
LL L,R;
int n,k,A[Maxn],F[Maxn];

inline LL Abs(int a) {return a>0?1LL*a:1LL*(-a);}
inline int check(LL x)
{
	for (int i=1;i<=n;i++) F[i]=i-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			if (Abs(A[i]-A[j])<=1LL*x*(i-j)) F[i]=min(F[i],F[j]+(i-j-1));
	for (int i=1;i<=n;i++) if (F[i]+(n-i)<=k) return 1;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	L=0,R=1LL*2e9;
	while (L<R)
	{
		LL Mid=(L+R)>>1;
		if (check(Mid)) R=Mid;else L=Mid+1;
	}
	printf("%I64d\n",L);
}