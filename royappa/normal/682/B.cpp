#include <bits/stdc++.h>

//http://codeforces.com/contest/682/problem/B

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] >= cur)
			cur++;
	}
	cout << cur << endl;
	exit(0);
}