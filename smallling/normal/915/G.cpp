#include <bits/stdc++.h>

using namespace std;

const int N = 2000020;
const int mo = 1e9 + 7;

int f[N];

int power(int x, int m)
{
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
	int n, k, ans = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
	{
		f[i] += power(i, n) - power(i - 1, n);
		if(f[i] < 0)f[i] += mo;
		if(f[i] >= mo)f[i] -= mo;
		for(int j = i + i; j <= k; j += i)
		{
			f[j] -= f[i];
			if(f[j] < 0)f[j] += mo;
		}
		f[i] += f[i - 1];
		if(f[i] >= mo)f[i] -= mo;
		ans += f[i] ^ i;
		if(ans >= mo)ans -= mo;
	}
	printf("%d\n", ans);
}