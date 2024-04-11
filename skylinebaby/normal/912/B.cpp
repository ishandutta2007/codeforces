#include<bits/stdc++.h>
#define int long long
using namespace std;
int pow(int t)
{
	if (t==0) return 1;
	if (t==1) return 2;
	if (t%2==0) return (pow(t/2)*pow(t/2));
	else return pow(t-1)*2;
}
main()
{
	int n,k;
	scanf("%lld %lld",&n,&k);
	if (k==1) 
	{
		printf("%lld\n",n);
		return 0;
	}
	int s = 0;
	while(n>0)
	{
		s++;
		n = n >> 1;
	}
	printf("%lld\n",pow(s)-1);
	return 0;
}