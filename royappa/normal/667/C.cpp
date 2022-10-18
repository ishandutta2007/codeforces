#include <bits/stdc++.h>

using namespace std;


typedef long long LL;

int f[10000+20][4];
int main()
{
	string s;
	cin >> s;
	/*
	f(p,2) = true if [p..n) can be broken up into suffixes such that no suffix is repeated, and the first suffix is of length 2
	f(p,3) = .. likewise

	*/
	int n = s.size();
	memset(f, 0, sizeof(f));
	f[n][2] = f[n][3] = 1;
	for (int p = n-1; p >= 5; p--)
	{
		for (int L = 2; L <= 3; L++)
		{
			if (p+L == n)
				f[p][L] = 1;
			else
			{
				for (int L2 = 2; L2 <= 3; L2++)
				{
					if (p+L+L2 <= n && (L != L2 || s.substr(p,L) != s.substr(p+L,L)))
						f[p][L] = f[p][L] || f[p+L][L2];
				}
			}
		}
	}
	set<string> res;
	for (int p = 5; p < n; p++)
	{
		for (int L = 2; L <= 3; L++)
		{
			if (p+L <= n && f[p][L])
			{
				res.insert(s.substr(p, L));
			}
		}
	}
	cout << res.size() << endl;
	for (auto x : res)
		cout << x << endl;
	exit(0);
}