#include <bits/stdc++.h>

int n, k, S, val, pos;

void query(int i) {printf("? %d\n", i); fflush(stdout);}

int nxt(int i) {return i == n ? 1 : i + 1;}

int pre(int i) {return i == 1 ? n : i - 1;}

int main()
{
	int x;
	std::cin >> n >> k; S = sqrt(n) + 1;
	for (int i = 1; i <= S; i++) query(1), scanf("%d", &x);
	if (n <= 90) for (int i = 1; i <= n; i++)
	{
		if (query(i), scanf("%d", &x), x != k)
			{val = x; pos = i; break;}
	}
	else for (int i = 1; i <= n; i += S * 2)
	{
		if (query(i), scanf("%d", &x), x != k)
			{val = x; pos = i; break;}
	}
	if (!pos) for (int i = 1; i <= n; i += S * 2)
		if (query(nxt(i)), scanf("%d", &x), x > k)
			return printf("! %d\n", i), fflush(stdout), 0;
	if (val > k) for (; (pos = pre(pos), query(pos),
		scanf("%d", &x), x > k););
	else for (; (pos = nxt(pos), query(pos),
		scanf("%d", &x), x < k););
	return printf("! %d\n", pos), fflush(stdout), 0;
}