#include <bits/stdc++.h>

const int matr[4][4] = {{8, 9, 1, 13},
{3, 12, 7, 5},
{0, 2, 4, 11},
{6, 10, 15, 14}};

int n;

int main()
{
	std::cin >> n;
	n >>= 2;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < n; j++)
				for (int h = 0; h < 4; h++)
					printf("%d ", (i * n + j) * 16 + matr[k][h]);
			puts("");
		}
	return 0;
}