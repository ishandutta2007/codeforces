#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
int n,Ql,Qr,l,r;
int A[Maxn];
LL Ans=(1<<30)-1,suml,sumr;

int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&Ql,&Qr);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),sumr+=A[i]*r;
	for (int i=0;i<=n;i++)
	{
		LL now=suml+sumr;
		if (i>n-i+1) now+=1LL*(i-(n-i+1))*Ql;
			else if (n-i>i+1) now+=1LL*(n-i-(i+1))*Qr;
		Ans=min(Ans,now);
		suml+=1LL*A[i+1]*l;
		sumr-=1LL*A[i+1]*r;
	}
	printf("%I64d\n",Ans);
}