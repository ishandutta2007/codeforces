#include <bits/stdc++.h>

typedef long long ll;

const int N = 1005;

int n, p = 2, q, a[N], t1, a1[N], t2, a2[N];
ll area, ar[N];

inline bool comp(int a, int b)
{
	return ar[a] < ar[b];
}

int main()
{
	int x; ll s;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		printf("2 1 %d %d\n", p, i); fflush(stdout);
		scanf("%d", &x); if (x == 1) p = i;
	}
	for (int i = 2; i <= n; i++) if (p != i)
	{
		printf("1 1 %d %d\n", p, i); fflush(stdout);
		scanf("%lld", &s);
		if (s > area) area = s, q = i;
		ar[i] = s;
	}
	for (int i = 2; i <= n; i++) if (p != i && q != i)
	{
		printf("2 1 %d %d\n", i, q); fflush(stdout);
		if (scanf("%d", &x), x == 1) a1[++t1] = i;
		else a2[++t2] = i;
	}
	std::sort(a1 + 1, a1 + t1 + 1, comp);
	std::sort(a2 + 1, a2 + t2 + 1, comp);
	printf("0 1 ");
	for (int i = 1; i <= t1; i++) printf("%d ", a1[i]);
	printf("%d ", q);
	for (int i = t2; i >= 1; i--) printf("%d ", a2[i]);
	return printf("%d\n", p), 0;
}