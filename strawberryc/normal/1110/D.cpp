#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e6 + 6;

int n, m, cnt[N], f[N][3][3];

int main()
{
	n = read(); m = read();
	while (n--) cnt[read()]++;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				for (int h = 0; h < 3; h++)
				{
					if (j + k + h > cnt[i]) continue;
					int delta = (cnt[i] - j - k - h) / 3;
					f[i][k][h] = std::max(f[i][k][h],
						f[i - 1][j][k] + h + delta);
				}
	std::cout << f[m][0][0] << std::endl;
	return 0;
}