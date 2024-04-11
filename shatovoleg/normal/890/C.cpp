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
	int used[200000 + 10];
	for (int i = 0; i < 2e5 + 10; ++i)
		used[i] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int v;
		cin >> v;
		if (used[v])
		{
			used[v] = false;
			used[i] = true;
		}
		else
		{
			used[i] = true;
			++ans;
		}
	}
	cout << ans << endl;
}