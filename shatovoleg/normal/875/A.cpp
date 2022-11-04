#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back

void UseFiles(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int get_sum(int a)
{
	int sm = 0;
	while (a)
	{
		sm += a % 10;
		a /= 10;
	}
	return sm;
}

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = max(n - 100, 0); i <= n; ++i)
		if (i + get_sum(i) == n)
			ans.pb(i);
	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << " ";
	cout << endl;
}