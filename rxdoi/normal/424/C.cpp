#include<cstdio>
#include<cmath>
using namespace std;

const int Maxn=1e6+19;
int x,Ans=0,n,S[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),Ans^=x;
	for (int i=1;i<=n;i++) S[i]=S[i-1]^i;
	for (int i=1;i<=n;i++)
	{
		int t=n%i,tt=n/i;
		if (tt%2==0) Ans^=S[t];else Ans^=(S[i-1]^S[t]);
	}
	printf("%d\n",Ans);
	return 0;
}