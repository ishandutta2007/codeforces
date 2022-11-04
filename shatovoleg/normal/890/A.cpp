#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()

signed main()
{
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> arr(6);
	int sm = 0;
	for (auto &x : arr)
	{
		cin >> x;
		sm += x;
	}
	for (int i = 0; i < 6 - 2; ++i)
		for (int j = i + 1; j < 6 - 1; ++j)
			for (int k = j + 1; k < 6; ++k)
				if ((arr[i] + arr[j] + arr[k]) * 2 == sm)
				{
					cout << "YES" << endl;
					return 0;
				}
	cout << "NO" << endl;
}