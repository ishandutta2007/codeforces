#include <bits/stdc++.h>
using namespace std;

int tot, num[8];

bool prime(int x)
{
	if (x < 2)
		return false;
	if (x % 2 == 0)
		return x == 2;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

int power(int a, int x, int p)
{
	int ans = 1;
	for (; x; x >>= 1)
	{
		if (x & 1)
			ans = 1ll * ans * a % p;
		a = 1ll * a * a % p;
	}
	return ans;
}

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	if (!prime(n + 1))
		puts("-1");
	else
	{
		int tmp = n;
		for (int i = 2; i * i <= tmp; i++)
			if (tmp % i == 0)
			{
				num[tot++] = i;
				while (tmp % i == 0) tmp /= i;
			}
		if (tmp > 1) num[tot++] = tmp;
		for (int b = x - 1; b > 1; b--)
		{
			bool flag = true;
			for (int i = 0; i < tot; i++)
				if (power(b, n / num[i], n + 1) == 1)
				{
					flag = false;
					break;
				}
			if (flag)
			{
				printf("%d\n", b);
				return 0;
			}
		}
		puts("-1");
	}
	return 0;
}