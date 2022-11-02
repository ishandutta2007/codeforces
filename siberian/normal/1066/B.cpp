#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main()
{
	int n, r;
	cin >> n >> r;
	r--;
	vector <int> a(n);
	int count = 0;
  for (int i = 0; i< n; i++)
	{
		cin >> a[i];
    if (a[i])
    count++;
  }
  if (!count)
  {
    cout << -1;
    return 0;
  }
	int pos = -1;
	int ans = 0;
	//	vector <int> b(n, 0);
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		int x = i + r;
		if (ans)
			x += r;
		for (int j = i; j <= min(x, n - 1); j++)
		{
			if (a[j] == 1)
			{
				flag = false;
				pos = j;
			}
		}
		i = pos;
		ans++;
		if (pos + r >= n - 1)
			break;
		if (flag)
		{
			cout << -1;
			return 0;
		}
	}
  if (pos == -1)
  {
    cout << -1;
    return 0;
  }
	cout << ans;
	return 0;
}