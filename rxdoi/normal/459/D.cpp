#include<cstdio>
#include<map>
using namespace std;

const int Maxn=1e6+19;
typedef long long LL;
map<int,int> Map;
int n,cnt;
int A[Maxn],A_cnt[Maxn],B_cnt[Maxn],F[Maxn];
LL C[Maxn],Ans;

inline void Getit(int &x) {int &y=Map[x];if (!y) y=++cnt;x=y;}
inline LL Query(int x) {LL Ans=0;while (x) Ans+=C[x],x-=x&-x;return Ans;}
inline void Update(int x) {while (x<=n) C[x]++,x+=x&-x;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		Getit(A[i]);
	}
	for (int i=1;i<=n;i++) F[i]=++A_cnt[A[i]];
	for (int i=n;i>=1;i--)
	{
		Ans+=Query(F[i]-1);
		Update(++B_cnt[A[i]]);
	}
	printf("%I64d\n",Ans);
}