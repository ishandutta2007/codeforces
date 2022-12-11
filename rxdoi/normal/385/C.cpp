#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int Maxn=1e7+19;
typedef long long LL;
int n,x,L,R,Q;
LL cnt[Maxn],A[Maxn],not_p[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),A[x]++;
	for (int i=2;i<=1e7;i++)
		if (!not_p[i])
			for (int j=i;j<=1e7;j+=i) not_p[j]=1,cnt[i]+=A[j];
	for (int i=1;i<=1e7;i++) cnt[i]+=cnt[i-1];
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d",&L,&R);L=min(L,(int)1e7);R=min(R,(int)1e7);
		printf("%I64d\n",cnt[R]-cnt[L-1]);
	}
}