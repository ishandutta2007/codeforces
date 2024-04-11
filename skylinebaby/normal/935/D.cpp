#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000007ll;
int a[123456];
int b[123456];
int poow (int x, int n)
{
	if (n==0) return 1;
	if (n%2==1) return (x*poow(x,n-1))%N; 
	int r = poow(x,n/2);
	return (r*r)%N;
}
main()
{
	int n,m;
	scanf("%lld %lld",&n,&m);
	int ans = 0;
	int pre = 1;
	for(int i = 0;i<n;i++) scanf("%lld",&a[i]);
	for(int i = 0;i<n;i++) scanf("%lld",&b[i]);
	for(int i = 0;i<n;i++)
	{
		if (a[i]==0&&b[i]==0)
		{
			int nee = ((m-1)*poow(2*m,N-2))%N;
			nee = (nee * pre) % N;
			ans = (ans + nee) % N;
			pre = (pre * poow(m,N-2))%N;
		}
		else if (a[i]==0)
		{
			int nee = ((m-b[i])*poow(m,N-2))%N;
			nee = (nee * pre) % N;
			ans = (ans + nee) % N;
			pre = (pre * poow(m,N-2))%N;			
		}
		else if (b[i]==0)
		{
			int nee = ((a[i]-1)*poow(m,N-2))%N;
			nee = (nee * pre) % N;
			ans = (ans + nee) % N;
			pre = (pre * poow(m,N-2))%N;
		}
		else 
		{
			if (b[i]>a[i]) break;
			if (a[i]==b[i]) continue;
			if (a[i]>b[i]) 
			{
				ans = (ans + pre)%N;
				break;
			}
		}
	}
	printf("%lld\n",ans);	
}