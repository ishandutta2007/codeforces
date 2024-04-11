#include <bits/stdc++.h>

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e6 + 5;

int n, m;

std::string s[N];
std::vector<int> sum[N], s2[N];
std::vector<char> ans[N];

int sum1(int l, int r, int x, int y)
{
	return sum[r][y] - sum[l - 1][y] - sum[r][x - 1] + sum[l - 1][x - 1];
}

int sum2(int l, int r, int x, int y)
{
	return s2[r][y] - s2[l - 1][y] - s2[r][x - 1] + s2[l - 1][x - 1];
}

bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s2[i][j] = sum1(Max(1, i - mid), Min(n, i + mid),
				Max(1, j - mid), Min(m, j + mid)) == 1ll * (mid * 2 + 1)
					* (mid * 2 + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans[i][j] = s2[i][j] ? 'X' : '.', s2[i][j] += s2[i][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s2[i][j] += s2[i - 1][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ((sum2(Max(1, i - mid), Min(n, i + mid),
				Max(1, j - mid), Min(m, j + mid)) > 0) ^ (s[i - 1][j - 1] == 'X'))
					return 0;
	return 1;
}

int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) std::cin >> s[i];
	for (int i = 0; i <= m; i++) sum[0].push_back(0);
	for (int i = 1; i <= n; i++)
	{
		sum[i].push_back(0);
		for (int j = 1; j <= m; j++)
			sum[i].push_back(sum[i][j - 1] + (s[i - 1][j - 1] == 'X'));
	}
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			sum[i][j] += sum[i - 1][j];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			s2[i].push_back(0), ans[i].push_back(0);
	int l = 0, r = n * m;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	std::cout << r << std::endl;
	check(r);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) putchar(ans[i][j]);
		puts("");
	}
	return 0;
}