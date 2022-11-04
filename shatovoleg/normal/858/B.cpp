#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define inf 2000000000
#define mod 1000000009

void useFiles(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int get_stage(int n, int m)
{
	return (n - 1) / m + 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pii> a(m);
	for (auto &x : a)
		cin >> x.F >> x.S;
	set<int> s;
	for (int f = 1; f < 1000; ++f)
	{
		bool flag = true;
		for (auto &x : a)
			if (get_stage(x.F, f) != x.S)
			{
				flag = false;
				break;
			}
		if (flag)
			s.insert(get_stage(n, f));
	}
	if (s.size() == 1)
		cout << *s.begin() << endl;
	else
		cout << -1 << endl;	
}