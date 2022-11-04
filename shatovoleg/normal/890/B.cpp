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
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		m[v] = i;
	}
	int mx = 1000000000, mxv;
	for (auto x : m)
		if (x.S < mx)
		{
			mx = x.S;
			mxv = x.F;
		}
	cout << mxv << endl;
}