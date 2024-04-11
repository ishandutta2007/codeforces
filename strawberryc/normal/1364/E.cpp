#include <bits/stdc++.h>

const int N = 2050;

int n, tmp[N];

int query(int x, int y)
{
	int res;
	printf("? %d %d\n", x + 1, y + 1); fflush(stdout);
	return scanf("%d", &res), res;
}

int solve(std::vector<int> a, int fis)
{
	if (a.size() == 1) return a[0];
	if (a.size() == 2) return a[0] == fis ? a[1] : a[0];
	std::vector<int> nxt; int pos = a[0] == fis ? a[1] : a[0], res = (1 << 19) - 1;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != pos)
			res &= (tmp[i] = query(a[i], pos));
	for (int i = 0; i < a.size(); i++) if (a[i] == pos || tmp[i] == res)
		nxt.push_back(a[i]);
	return solve(nxt, pos);
}

int main()
{
	srand(time(0));
	std::vector<int> a;
	int pos, res;
	std::cin >> n;
	while (1)
	{
		int x = rand() % n, res = (1 << 19) - 1;
		for (int T = 1; T <= 20; T++)
		{
			int y; while (y = rand() % n, y == x);
			res &= query(x, y);
		}
		if (__builtin_popcount(res) <= 5) {pos = x; break;}
	}
	res = (1 << 19) - 1;
	for (int i = 0; i < n; i++) if (pos != i) res &= (tmp[i] = query(pos, i));
	for (int i = 0; i < n; i++) if (i == pos || tmp[i] == res) a.push_back(i);
	int p0 = solve(a, pos);
	for (int i = 0; i < n; i++) tmp[i] = i == p0 ? 0 : query(i, p0);
	printf("! ");
	for (int i = 0; i < n; i++) printf("%d ", tmp[i]);
	return puts(""), fflush(stdout), 0;
}