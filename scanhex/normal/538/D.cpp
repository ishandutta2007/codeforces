#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	vector<string> matr(n);
	for (int i = 0; i < n; ++i)
		cin >> matr[i];
	vector<int> xs;
	vector<int> ys;
	for (int i = -n + 1; i < n; ++i)
		for (int j = -n + 1; j < n; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			bool f = true;
			for (int k = 0; k < n; ++k)
				for (int k1 = 0; k1 < n; ++k1)
				{
					if (k + i < 0 || k + i >= n || k1 + j < 0 || k1 + j >= n || matr[k][k1] != 'o')
						continue;
					f &= (matr[k + i][k1 + j] != '.');
				}
			if (f)
			{
				xs.push_back(i);
				ys.push_back(j);
			}
		}
	for (int it = 0; it < xs.size(); ++it)
	{
		int i = xs[it];
		int j = ys[it];
		for (int k = 0; k < n; ++k)
			for (int k1 = 0; k1 < n; ++k1)
			{
				if (k + i < 0 || k + i >= n || k1 + j < 0 || k1 + j >= n || matr[k][k1] != 'o')
					continue;
				if (matr[k + i][k1 + j] == 'x')
					matr[k + i][k1 + j] = '.';
			}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (matr[i][j] == 'x')
			{
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
	vector<vector<char>> ans(2 * n - 1, vector<char>(2 * n - 1, '.'));
	for (int i = 0; i < xs.size(); ++i)
		ans[xs[i] + n - 1][ys[i] + n - 1] = 'x';
	ans[n - 1][n - 1] = 'o';
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		for (int j = 0; j < 2 * n - 1; ++j)
			cout << ans[i][j];
		cout << endl;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}