#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back

typedef long long ll;
typedef long double ld;

int main()
{
	string s;
	cin >> s;
	int n = len(s);
	vector<vector<vector<int>>> cnt(26, vector<vector<int>>(n, vector<int>(26, 0)));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			++cnt[s[i] - 'a'][j][s[(i + j) % n] - 'a'];
	vector<int> flag(26, 0);
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < n; ++j)
		{
			int a = 0;
			for (int k = 0; k < 26; ++k)
				if (cnt[i][j][k] == 1)
					++a;
			if (a > flag[i])
				flag[i] = a;
		}
	int c = 0;
	for (auto &x : flag)
		c += x;
	cout << fixed << setprecision(10) << (ld)c / (ld)n << endl;
}