#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map> 
#define maxn 200005
#define mod 1000000007
#define ll long long
using namespace std;
int d[maxn];
int ntm[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for(int i = 1; i <= n; i++)	
		scanf("%d", &d[i]), 
		d[i]++, 
		ans -= d[i], 
		ntm[i - d[i]]++;
	int ncnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(ntm[i - 1 - ncnt])
			ncnt++;
		ans += ncnt;
		ntm[i - d[i]]--;
	}
	printf("%lld\n", ans);
	return 0;
 }