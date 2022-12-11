#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
int n;LL a,b,c,Ans;

LL gcd(LL a,LL b) {return !b?a:gcd(b,a%b);}
LL Lcm(LL a,LL b) {return a/gcd(a,b)*b;}

int main()
{
	scanf("%d",&n);
	for (a=max(n-100,1);a<=n;a++)
		for (b=max(n-100,1);b<=n;b++)
			for (c=max(n-100,1);c<=n;c++)
			{
				LL tmp=Lcm(a,Lcm(b,c));
				if (tmp>Ans) Ans=tmp;
			}
	printf("%I64d\n",Ans);
}