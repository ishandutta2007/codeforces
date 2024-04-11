#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
using namespace std;
#define INF 998244353
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)
#define int long long
vector <int> a;
int n, m, k;

bool found(int x)
{
	int cnt = 1;
	int box = k;
  for (int j = x; j < n; j++)
	{
    int i = a[j];
		if (box - i < 0)
    {
      box = k - i;
      cnt++;
    }
    else
    {
      box -= i;
    }
	}
  if (cnt > m)
  return false;
	return true;
}

signed main()
{
	FAST;


	cin >> n >> m >> k;

	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int l = 0; int r = n; int mid;
	while (l < r - 1)
	{
		mid = (l + r) / 2;
		if (found(mid))
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	if (found(r - 1))
		r--;
	cout << n-r;
	return 0;
}