#include<cstdio>
using namespace std;

typedef long long LL;
LL n,k,d1,d2;
int t;

inline int check(LL d1,LL d2)
{
	LL b=(k-d1+d2)/3;
	LL a=d1+b,c=b-d2;
	if (a+b+c!=k||a<0||b<0||c<0) return 0;
	if (a<=n/3&&b<=n/3&&c<=n/3) {puts("yes");return 1;}
	return 0;
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
		if (n%3) {puts("no");continue;}
		if (!check(d1,d2)) 
			if (!check(d1,-d2))
				if (!check(-d1,d2)) 
					if (!check(-d1,-d2)) puts("no");
	}
}