#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

typedef long long LL;
LL A,B,Ans;

int main()
{
	scanf("%I64d%I64d",&A,&B);
	if (A<B) swap(A,B);
	while (B!=1)
	{
		Ans+=A/B,A%=B;
		if (A<B) swap(A,B);
	}
	printf("%I64d\n",Ans+A);
}