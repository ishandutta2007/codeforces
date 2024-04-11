#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	long long sum = 0;
	for(int i = n; i >= n - k + 1; i--) sum += i;
	printf("%lld\n", sum);
	long long t = 1;
	int x = -1;
	for(int i = 0; i < n; i++)
	{
		int y;
		scanf("%d", &y);
		if(y >= n - k + 1)
		{
			if(x == -1) x = i;
			else
			{
				t = t * (i - x);
				t = t % mod;
				x = i;
			}
		}
	}
	printf("%lld\n", t);
	return 0;
}