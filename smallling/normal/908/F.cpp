#include <bits/stdc++.h>

using namespace std;

const int N = 300030;
const int inf = 0x3f3f3f3f;

int n, a[N], b[N], c[N];
long long ans1[N], ans2[N];

void work(int *a, int *b, long long *ans)
{
	int l = 1, r = 0;
	for(int i = 1; i < *a && l <= *b; i++)
	{
		int lx = a[i], rx = a[i + 1];
		if(b[l] > rx)continue;
		while(r < *b && b[r + 1] < rx)r++;
		long long nowmin = rx - b[l];
		for(int j = l; j < r; j++)
			nowmin = min(nowmin, 0ll + b[j] - lx + rx - b[j + 1]);
		nowmin = min(nowmin, 0ll + b[r] - lx);
		ans[i] = nowmin;
		l = r + 1;
	}
}

int main()
{
	scanf("%d", &n);
	a[++*a] = -inf;
	for(int i = 1; i <= n; i++)
	{
		int x;
		char s[2];
		scanf("%d%s", &x, s);
		if(s[0] == 'G')a[++*a] = x;
		if(s[0] == 'R')b[++*b] = x;
		if(s[0] == 'B')c[++*c] = x;
	}
	a[++*a] = inf;
	if(*a == 2)
	{
		printf("%d\n", b[*b] - b[1] + c[*c] - c[1]);
		return 0;
	}
	work(a, b, ans1);
	work(a, c, ans2);
	long long ans = 0;
	ans = ans1[1] + ans1[*a - 1] + ans2[1] + ans2[*a - 1];
	for(int i = 2; i < *a - 1; i++)
		ans += min(ans1[i] + ans2[i] + a[i + 1] - a[i], 0ll + ((ans1[i] || ans2[i]) ? 2 : 1) * (a[i + 1] - a[i]));
	printf("%I64d\n", ans);
}