#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n,k;
	cin>> n >> k;
	int i = 0;
	for (; n <= k; i++, n*=3, k*=2);
	cout << i;
}