#include <bits/stdc++.h>

//http://codeforces.com/contest/670/problem/A

using namespace std;


typedef long long LL;


int main()
{
	int n;
	cin >> n;
	int lo = 1<<30, hi = 0;
	if (n <= 2)
	{
		lo = 0;
		hi = n;
	}
	else if (n <= 7)
	{
		lo = max(0, n-5);
		hi = 2;
	}
	else
	{
		for (int start = 0; start < 7; start++)
		{
			lo = ((n-5)/7)*2+min(2, (n-5)%7);
			hi = n/7*2+min(n%7, 2);
		}
	}
	cout << lo << " " << hi << endl;
	exit(0);
}