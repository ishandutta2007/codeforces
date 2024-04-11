#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a,b,c;

LL gcd(LL a,LL b)
{
	if (a<b)
		swap(a,b);
	return b==0 ? a:gcd(b,a%b);
}

int work()
{
	
	cin>>a>>b;
	if (a<b)
		swap(a,b);
	if (a==b)
	{
		cout<<0;
		return 0;
	}
	c=a-b;
	LL mi=LLINF;
	LL ans;
	RPT(i,1,sqrt(c)+1)
	{
		if (c%i!=0)
			continue;
		LL tem=i;
		if (a%tem==0)
		{
			if (a*b/tem<mi)
			{
				//WRT(mi);
				mi=a*b/tem;
				ans=0;
			}
		}
		else
		{
			LL k=(a/tem+1)*tem-a;
			if ((a+k)*(b+k)/tem<mi)
			{
				mi=(a+k)*(b+k)/tem;
				ans=k;
			}
		}
		tem=c/i;
		if (a%tem==0)
		{
			if (a*b/tem<mi)
			{
			//	WRT(mi);
				mi=a*b/tem;
				ans=0;
			}
		}
		else
		{
			LL k=(a/tem+1)*tem-a;
			if ((a+k)*(b+k)/tem<mi)
			{
				mi=(a+k)*(b+k)/tem;
				ans=k;
			}
		}
	}
	cout<<ans;
	return 0;
}

int main()
{
	work();
	return 0;
	cout<<endl;
	LL ans=LLINF;
	LL f=0;
	RPT(k,0,1000)
	{
		if ((a+k)*(b+k)/gcd(a+k,b+k)<ans)
		{
			ans=(a+k)*(b+k)/gcd(a+k,b+k);
			f=k;
		}
	}
	WRT(f);
	return ~~(0^_^0);
}