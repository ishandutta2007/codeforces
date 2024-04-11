#include <bits/stdc++.h>

using namespace std;

const int mo = 1e9 + 9;
const int N = 100010;

char s[N];

int power(int x, int m)
{
	if(x < 0)x += mo;
	int nowans = 1;
	while(m)
	{
		if(m & 1)nowans = 1ll * nowans * x % mo;
		x = 1ll * x * x % mo;
		m >>= 1;
	}
	return nowans;
}

int main()
{
	int n, a, b, k;
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", s);
	int inva = power(a, mo - 2);
	int invb = power(b, mo - 2);
	int nowv = power(a, n), ans = 0, ans1 = 0;
	for(int i = 0; i < k; i++)
	{
		if(s[i] == '+')ans += nowv;
		else ans -= nowv;
		if(ans >= mo)ans -= mo;
		if(ans < 0)ans += mo;
		nowv = 1ll * nowv * inva % mo * b % mo;
		if(i < (n + 1) % k)
		{
			ans1 = ans;
		}
	}
	int x = (n + 1) / k;
	int q = 1ll * b * inva % mo;
	q = power(q, k);
	if(q == 1)
	{
		int Ans = 1ll * ans * x % mo;
		Ans += ans1;
		Ans %= mo;
		printf("%d\n", Ans);
		return 0;
	}
	int inv = power(1 - q, mo - 2);
	int Ans = 1ll * ans * (1 - power(q, x)) % mo * inv % mo;
	if(Ans < 0)Ans += mo;
	Ans += 1ll * ans1 * power(q, x) % mo;
	Ans %= mo;
	printf("%d\n", Ans);
}