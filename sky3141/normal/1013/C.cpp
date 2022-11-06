#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
const long long INF = 2000000000000000000;

int n, x;
long long a[MAXN*2];
long long ans = INF;

int main()
{
	scanf("%d", &n);
	if(n == 1)
	{
		printf("0");
		return 0;
	}
	n *= 2;
	for(int i=0; i<n; ++i)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	ans = min(ans, (a[n/2-1] - a[0]) * (a[n-1] - a[n/2]));
	for(int i=1; i<n/2; ++i)
	{
		ans = min(ans, (a[n-1] - a[0]) * (a[i+n/2-1] - a[i]));
	}
	
	printf("%I64d", ans);
	
	return 0;
}