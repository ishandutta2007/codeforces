#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	for (int x = 0; x * a <= n; ++x)
	{
		if ((n - x * a) % b == 0)
		{
			int y = (n - x * a) / b;
			int cur = 0;
			vector<int> ans;
			for (int i = 0; i < x; ++i)
			{
				for (int j = 0; j < a - 1; ++j)
					ans.push_back(cur + j + 1);
				ans.push_back(cur);
				cur += a;
			}
			for (int i = 0; i < y; ++i)
			{
				for (int j = 0; j < b - 1; ++j)
					ans.push_back(cur + j + 1);
				ans.push_back(cur);
				cur += b;
			}
			for (auto& x : ans)
				cout << x + 1 << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}