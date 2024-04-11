#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

typedef long long LL;
int n,Ans;LL L,R,res;

int C(LL x)
{
	int t=0;
	for (LL i=x;i;i>>=1) t+=i&1;
	return t;
}

int main()
{
	for (scanf("%d",&n);n--;)
	{
		scanf("%I64d%I64d",&L,&R);Ans=-1;
		for (LL i=L;i<=R;i+=~i&-~i) if (C(i)>Ans) Ans=C(i),res=i;
		printf("%I64d\n",res);
	}
}