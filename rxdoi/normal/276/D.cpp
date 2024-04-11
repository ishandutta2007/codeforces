#include<cstdio>
using namespace std;

typedef long long LL;
LL l,r;

int main()
{
	scanf("%I64d%I64d",&l,&r);
	if (l==r) puts("0");
		else 
		{
			for (int i=60;i>=0;i--)
				if ((l>>i)!=(r>>i)) {printf("%I64d\n",(1LL<<i+1)-1);break;}
		}
}