#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
using namespace std;
int n, a[maxn];
int main()
{
	int s;
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int mid = (n + 1) / 2;
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == mid)
			ans += abs(a[i] - s);
		else if(i < mid)	
			ans += max(0, a[i] - s);
		else ans += max(0, s - a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}