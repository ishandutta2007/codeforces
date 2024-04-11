#include<cstdio>
using namespace std;

typedef long long LL;
LL n,d;

int main()
{
	scanf("%I64d%I64d",&n,&d);
	LL tmp=n;
	while (tmp&&tmp%10!=9) tmp--;
	if (n-tmp<=d) 
	{
		d-=n-tmp,n=tmp;
		for (LL i=1;i<=n;i*=10)
		{
			LL tmp=(n/(i*10));
			while (tmp&&tmp%10!=9) tmp--;
			if (!tmp) break;
			LL New=tmp*(i*10)+n%(i*10);
			if (n-New>d) break;
			d-=n-New;n=New;
		}
	}
	printf("%I64d\n",n);
}