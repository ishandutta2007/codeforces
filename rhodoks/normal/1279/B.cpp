#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,s;
int a[MAXN];
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>s;
		int mx=0;
		int ans=0;
		int cnt=0;
		int id=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int it;
		for (it=1;it<=n;it++)
		{
			if (a[it]>mx)
			{
				mx=a[it];
				id=it;
			}
			if (s<a[it])
				break;
			s-=a[it];
			cnt++;
		}
		ans=cnt;
		if (it<=n)
		{
			if (id<it)
			{
				s+=mx;
				cnt--;
			}
			else
			{
				it++;
			}
		}
		for (int i=it;i<=n;i++)
		{
			if (s<a[i])
				break;
			s-=a[i];
			cnt++;
		}
		if (ans<cnt)
			cout<<id<<endl;
		else
			cout<<0<<endl;
	}
	return ~~(0^_^0);
}