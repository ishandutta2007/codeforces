#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100000+19;
int n,x;
long long cnt[Maxn],F[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),cnt[x]++;
	for (int i=1;i<Maxn;i++)
		F[i]=max(F[i-1],1LL*i*cnt[i]+(i>=2?F[i-2]:0));
	printf("%I64d\n",F[Maxn-1]);
}