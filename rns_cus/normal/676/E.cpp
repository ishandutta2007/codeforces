#include <cstdio>

const int mod1 = 1;
const int mod2 = 2e9+9;
const int mod3 = 2e9+9;
const int mod4 = 2e9+9;
const int mod5 = 2e9+9;

char s[10];
int a[100001];
bool q[100001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int cnt = 0;
	for (int i = n; i >= 0; --i)
	{
		scanf("%s", s);
		if (s[0] == '?')
			q[i] = true;
		else
		{
			++cnt;
			bool sgn = 0;
			for (int j = 0; s[j]; ++j)
			{
				if (s[j] == '-')
					sgn ^= 1;
				else
					a[i] = a[i] * 10 + (s[j] - '0');
			}
			if (sgn)
				a[i] *= -1;
		}
	}
	///if(n ==42338 && k == 10000) printf("%d %d \n", cnt, n + 1);
	if (cnt == n + 1)
	{
		long long ans1 = a[0] % mod1;
		long long ans2 = a[0] % mod2;
		long long ans3 = a[0] % mod3;
		long long ans4 = a[0] % mod4;
		long long ans5 = a[0] % mod5;
		for (int i = 1; i <= n; ++i)
		{
			ans1 = (ans1 * k % mod1 + a[i]) % mod1;
			ans2 = (ans2 * k % mod2 + a[i]) % mod2;
			ans3 = (ans3 * k % mod3 + a[i]) % mod3;
			ans4 = (ans4 * k % mod4 + a[i]) % mod4;
			ans5 = (ans5 * k % mod5 + a[i]) % mod5;
			if (ans1 < 0)
				ans1 += mod1;
			if (ans2 < 0)
				ans2 += mod2;
			if (ans3 < 0)
				ans3 += mod3;
				if (ans4 < 0)
				ans4 += mod4;
				if (ans5 < 0)
				ans5 += mod5;
		}
		if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0 && ans5 == 0)
			puts("Yes");
		else
			puts("No");
	}
	else if (k == 0)
	{
		if (cnt & 1)
		{
			if (q[n] || (!q[n] && a[n] == 0))
				puts("Yes");
			else
				puts("No");
		}
		else
		{
			if (!q[n] && a[n] == 0)
				puts("Yes");
			else
				puts("No");
		}
	}
	else
	{
		if (n & 1)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}