#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;


nagai inter(nagai a, nagai b, nagai c, nagai d)
{
	return min(b, d) - max(a, c);
}
nagai gcd(nagai a, nagai b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai l, r, t;
	cin >> l >> r >> t;
	nagai l1, r1, t1;
	cin >> l1 >> r1 >> t1;
	nagai g = gcd(t, t1);
	nagai len = r - l + 1;
	nagai len1 = r1 - l1 + 1;
	if (l < l1)
		swap(l, l1), swap(len, len1);
	l -= (l - l1) / g * g;
	nagai ans = inter(l, l + len, l1, l1 + len1);
	l -= g;
	ans = max(ans, inter(l, l + len, l1, l1 + len1));
	cout << max(ans, (nagai)0) << '\n';
	return 0;
}