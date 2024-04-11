#include<bits/stdc++.h>
#define int long long
using namespace std;
int ar[201010];
main()
{
	int n,x;
	scanf("%lld %lld",&n,&x);
	for(int i = 0;i<n;i++) scanf("%lld",&ar[i]);
	sort(ar,ar+n);
	int ans = 0;
	int s = (n-1)/2;
	if (ar[s]<=x) 
	{
		for(int i = s;i<n;i++) 
		{
			if (ar[i]<x) ans += x-ar[i];	
		}
	}
	else
	{
		for(int i = 0;i<=s;i++) 
		{
			if (ar[i]>x) ans += ar[i]-x;
		}
	}
	printf("%lld\n",ans);
	return 0;
}