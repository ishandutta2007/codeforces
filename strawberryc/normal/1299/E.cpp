#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 805;

int n, ans[N], pos[N];
bool vis[N], odd[N];

void jjd(int T)
{
	int x; bool vi = 0;
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		printf("? %d ", n - (T - 1) * 2 - 1);
		for (int j = 1; j <= n; j++) if (!vis[j] && i != j)
			printf("%d ", j);
		puts(""); fflush(stdout);
		if (read(x), x)
		{
			if (!vi) vi = 1, ans[pos[T] = i] = T;
			else ans[pos[n - T + 1] = i] = n - T + 1;
		}
	}
	vis[pos[T]] = vis[pos[n - T + 1]] = 1;
}

void output()
{
	if (ans[1] > n / 2) for (int i = 1; i <= n; i++)
		ans[i] = n + 1 - ans[i];
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	puts("");
}

int q3(int u)
{
	int x;
	printf("? 3 %d %d %d\n", pos[1], pos[2], u); fflush(stdout);
	if (read(x), x) return 0;
	printf("? 3 %d %d %d\n", pos[2], pos[3], u); fflush(stdout);
	if (read(x), x) return 1;
	return 2;
}

int q5(int u)
{
	int x, mi = (1019 - n) % 5;
	printf("? 5 %d %d %d %d %d\n", pos[1], pos[2], pos[3], pos[n], u);
	fflush(stdout); if (read(x), x) return mi;
	printf("? 5 %d %d %d %d %d\n", pos[1], pos[2], pos[3], pos[n - 1], u);
	fflush(stdout); if (read(x), x) return (mi + 1) % 5;
	printf("? 5 %d %d %d %d %d\n", pos[1], pos[2], pos[3], pos[n - 2], u);
	fflush(stdout); if (read(x), x) return (mi + 2) % 5;
	printf("? 5 %d %d %d %d %d\n", pos[1], pos[2], pos[3], pos[n - 3], u);
	fflush(stdout); if (read(x), x) return (mi + 3) % 5;
	return (mi + 4) % 5;
}

int orz(int x, int y, int u)
{
	printf("? 7 "); int tmp;
	for (int i = 1; i <= 4; i++) if (i != x) printf("%d ", pos[i]);
	for (int i = n - 3; i <= n; i++) if (i != y) printf("%d ", pos[i]);
	printf("%d\n", u); fflush(stdout);
	return read(tmp), tmp;
}

int q7(int u)
{
	int x, mi = (3500 - 3 * n) % 7;
	if (orz(4, n, u)) return mi;
	if (orz(3, n, u)) return (mi + 6) % 7;
	if (orz(3, n - 1, u)) return (mi + 5) % 7;
	if (orz(2, n - 1, u)) return (mi + 4) % 7;
	if (orz(2, n - 2, u)) return (mi + 3) % 7;
	if (orz(1, n - 2, u)) return (mi + 2) % 7;
	return (mi + 1) % 7;
}

int q8(int u)
{
	int res = odd[u], x;
	if (res) printf("? 4 %d %d %d %d\n", pos[2], pos[3], pos[4], u);
	else printf("? 4 %d %d %d %d\n", pos[1], pos[2], pos[3], u);
	fflush(stdout); if (read(x), x) res += 2;
	printf("? 8 ");
	for (int i = 1; i <= 4; i++) if (i % 4 != res) printf("%d ", pos[i]);
	for (int i = 1; i <= 4; i++) printf("%d ", pos[n - i + 1]);
	printf("%d\n", u); fflush(stdout); if (!res) res = 4;
	if (read(x), x) res += 4;
	return res % 8;
}

int main()
{
	int x;
	read(n);
	jjd(1);
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		printf("? 2 %d %d\n", pos[1], i); fflush(stdout);
		if (read(x), x) odd[i] = 1;
	}
	for (int i = 2; i <= 4 && i <= n / 2; i++)
	{
		jjd(i);
		if (odd[pos[i]] ^ (i & 1)) Swap(pos[i], pos[n - i + 1]),
			Swap(ans[pos[i]], ans[pos[n - i + 1]]);
	}
	if (n <= 8) return output(), 0;
	for (int i = 1; i <= n; i++) if (!vis[i])
		ans[i] = (q3(i) * 280 + q5(i) * 336 + q7(i) * 120 + q8(i) * 105) % 840;
	return output(), 0;
}