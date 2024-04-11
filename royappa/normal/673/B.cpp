#include <bits/stdc++.h>

//http://codeforces.com/contest/673/problem/B

using namespace std;


typedef long long LL;


int main()
{
	int n, m;
	cin >> n >> m;
	int max2 = 0, min1 = 1<<30;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		int mn = min(a, b);
		int mx = max(a, b);
		max2 = max(max2, mn);
		min1 = min(min1, mx);
	}
	int num = 0;
	for (int i = 1; i <= n-1; i++)
	{
		// div2 = 1..i, rest is i+1..n
		if (max2 <= i && min1 >= i+1)
			num++;
	}
	cout << num << endl;
	exit(0);
}