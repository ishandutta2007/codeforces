#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long 
using namespace std;
ll a[maxn];
ll n;
int k;
int main()
{
 	ll ans = -1;
 	scanf("%I64d%d", &n, &k);
 	for(int i = 1; i <= k; i++)
 		scanf("%I64d", &a[i]);
 	int pl = 0;
 	for(int i = 1; i <= k; i++)
 	{
 		ll nans = n / a[i] * a[i];
 		if(nans > ans) ans = nans, pl = i;
	 }
	printf("%d %I64d\n", pl, n / a[pl]);
	return 0;
 }