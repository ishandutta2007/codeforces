#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	long long M = pow(2, (long long)(log2l(n) + 1)) - 1;
	long long ans = (k > 1) ? M : n;
	cout << ans;
}