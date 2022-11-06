#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;

int n, x;
int a[MAXN];
int t[MAXN], d[MAXN];

int main()
{
	int cur = 0;
	scanf("%d %d", &n, &x);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
		++t[a[i]];
		if(t[a[i]] > 1)
		{
			printf("0");
			return 0;
		}
	}
	for(int i=0; i<n; ++i)
	{
		if((a[i] & x) != a[i] && t[a[i]&x])
		{
			printf("1");
			return 0;
		}
		++d[a[i]&x];
	}
	for(int i=0; i<=100000; ++i)
	{
		if(d[i] > 1)
		{
			printf("2");
			return 0;
		}
	}
	
	printf("-1");
	
	return 0;
}