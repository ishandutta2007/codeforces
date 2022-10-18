#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main()
{
	long long n;
	scanf("%lld", &n);
	if(n == 1)
	{
		printf("1\n");
		return 0;
	}
	long long s = 0;
	long long v = 1;
	for(long long i = 2; i*i <= n; i++) 
	{
		if(n%i==0) 
		{
			v = i;
			while(n%i == 0) n/= i;	
			break;
		}
	}
	if(v == 1) 
	{
		printf("%lld\n",n);
		return 0;
	}
	if(n == 1)
	{
		printf("%lld\n",v);
		return 0;
	}
	printf("1\n");
	return 0;
 }