#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, k;
	//freopen("bracket-expression.in", "r", stdin);
	//freopen("bracket-expression.out", "w", stdout);
	cin >> n >> m >> k;
	vector<int> arr;
	arr.resize(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	int pl;
	cin >> pl;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int dif = 0;
		for (int j = 0; j < n; j++)
			dif += abs(((arr[i] >> j) % 2) - ((pl >> j) % 2));
		if (dif <= k)
			ans++;
	}
	cout << ans;
	return 0;
}