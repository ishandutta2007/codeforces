#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	intl x;
	cin >> x;
	vector <pair <intl, intl> > ans;
	for(intl n = 2; n < 1450000; n ++)
	{
		intl sum_k = n * (n + 1) / 2;
		intl sum_sq = n * (n + 1) * (2 * n + 1) / 6;
		intl lhs = n * n - sum_k;
		intl rhs = x - sum_sq + n * sum_k;
		if(rhs % lhs == 0)
		{
			intl tmp = rhs / lhs;
			if(tmp >= n)
			{
				ans.push_back(make_pair(n - 1, tmp - 1));
				ans.push_back(make_pair(tmp - 1, n - 1));
			}
		}
	}
	sort(ans.begin(), ans.end());
	auto it = unique(ans.begin(), ans.end());
	ans = vector <pair <intl, intl> > (ans.begin(), it);
	cout << ans.size() << '\n';
	for(auto &p : ans)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}