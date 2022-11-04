#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back

typedef long long ll;
typedef long double ld;

int main()
{
	int n;
	cin >> n;
	vector<int> d(n, 0);
	set<int> s;
	s.insert(0);
	for (int i = 1; i < n; ++i)
	{
		int p;
		cin >> p;
		d[i] = d[p - 1] + 1;
		if (s.count(d[i]))
			s.erase(d[i]);
		else
			s.insert(d[i]);
	}
	cout << len(s) << endl;
}