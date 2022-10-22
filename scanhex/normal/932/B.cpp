#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 2;

vector<int> ans(MX, -1);

int get(int x)
{
	if (x < 10)
		return x;
	if (ans[x] != -1)
		return ans[x];
	int mult = 1;
	while (x)
	{
		if (x % 10)
			mult *= x % 10;
		x /= 10;
	}
	return ans[x] = get(mult);
}

int main()
{
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	vector<vector<int>> pref(10, vector<int>(MX));
	for (int i = 0; i < MX - 1; ++i)
	{
		for (int j = 0; j < 10; ++j)
			pref[j][i + 1] = pref[j][i];
		pref[get(i)][i + 1]++;
	}
	while (q--)
	{
		int l, r, x;
		cin >> l >> r >> x;
		++r;
		cout << pref[x][r] - pref[x][l] << '\n';
	}
}