#include <bits/stdc++.h>

//http://codeforces.com/contest/673/problem/0 (A)
using namespace std;


typedef long long LL;


int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int res = 0, boring = 0;
	for (int m = 1; m <= 90; m++)
	{
		res++;
		if (find(v.begin(), v.end(), m) == v.end())
		{
			boring++;
			if (boring == 15)
				break;
			continue;
		}
		boring = 0;
	}
	cout << res << endl;
	exit(0);
}