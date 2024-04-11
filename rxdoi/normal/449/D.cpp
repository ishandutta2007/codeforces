#include<cstdio>
using namespace std;

const int Maxn=1e6+19,Mod=1e9+7;
typedef long long LL;
int b[1<<21],c[1<<21],pow[Maxn],n,x;
LL Ans;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&x),b[x]++;
	pow[0]=1;
	for (int i=1;i<=n;i++) pow[i]=pow[i-1]*2%Mod;
	for (int i=0;i<20;i++)
		for (int j=0;j<(1<<20);j++)
			if (!(j>>i&1)) b[j]+=b[j|(1<<i)];else c[j]++;
	for (int i=0;i<(1<<20);i++)
	{
		LL tmp=pow[b[i]]-1;
		if (c[i]&1) Ans=(Ans-tmp+Mod)%Mod;else Ans=(Ans+tmp)%Mod;
	}
	printf("%I64d\n",Ans);
}