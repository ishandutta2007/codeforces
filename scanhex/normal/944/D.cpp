#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;
typedef long double db;
typedef complex<db> cp;


int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int C = 26;
	int n = s.size();
	vector<vector<vector<int>>> cnt(C, vector<vector<int>>(n, vector<int>(C)));
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < n; ++j)
		{
			int j1 = i + j;
			if (j1 >= n)
				j1 -= n;
			++cnt[s[i] - 'a'][j][s[j1] - 'a'];
		}
	db ans = 0;
	for (int i = 0; i < C; ++i)
	{
		db mx = 0;
		for (int j = 1; j < n; ++j)
		{
			int c = 0;
			int all = 0;
			for (int k = 0; k < C; ++k)
			{
				c += cnt[i][j][k] == 1;
				all += cnt[i][j][k];
			}
			mx = max(mx, (db)c / all);
		}
//		cerr << count(s.begin(), s.end(), 'a' + i) << endl;
		ans += mx * count(s.begin(), s.end(), 'a' + i);
	}
	cout.precision(30);
	ans /= n;
	cout << ans << endl;
}