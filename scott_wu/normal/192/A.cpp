#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll tri[100100];

int main()
{
	for (int i = 0; i < 100000; i++)
		tri[i] = ((ll)i * ((ll)i-1)) / 2;
	ll n; cin >> n;
	for (int i = 2; i < 100000; i++)
	{
		int lo = 2, hi = 99999;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			if (tri[i] + tri[mid] < n)
				lo = mid + 1;
			else
				hi = mid;
		}
		if (tri[i] + tri[lo] == n)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}