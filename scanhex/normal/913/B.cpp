#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> ch(n);
	for (int i = 1; i < n; ++i)
	{
		int x; 
		cin >> x;
		--x;
		ch[x].push_back(i);
	}
	vector<bool> leaf(n);
	for (int i = n - 1; i >= 0; --i)
	{
		leaf[i] = ch[i].size() == 0;
		int cnt = 0;
		for (int v : ch[i])
			if (leaf[v])
				++cnt;
		if (cnt < 3 && !leaf[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}