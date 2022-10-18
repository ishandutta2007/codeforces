/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define double long double
#define int long long
#define len(a) (int)a.size()
using namespace std;
int n,P;
double p;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();scanf("%Lf",&p);
	P=p*10000;
	// cout<<P<<endl;
	int f=2ll*n*(n-1)*(n-2);
	for (int k=0;k<=n;k++)
	{
		int now=3ll*k*(n-k)*(n-k-1)+6ll*k*(k-1)*(n-k)+2ll*k*(k-1)*(k-2);
		now*=10000;
		if (now>=P*f)
		{
			printf("%lld\n",k);
			return 0;
		}
	}
}