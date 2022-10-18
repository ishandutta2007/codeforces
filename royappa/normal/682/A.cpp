#include <bits/stdc++.h>

//http://codeforces.com/contest/682/problem/A

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int n, m;
	cin >> n >> m;

	LL tot = 0;
	for (int x = 1; x <= n; x++)
	{
		// how many y are there, such that (x+y)%5 = 0
		// means y%5 = 5-x%5
		int k = 5-x%5;
		tot += m/5;
		if (m%5 >= k) tot++;
	}
	cout << tot << endl;
	exit(0);
}