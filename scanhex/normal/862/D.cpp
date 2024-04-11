#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int n;
int cnt;

// count of ones
int get(int l, int r)
{
	string s;
	for (int i = 0; i < l; ++i)
		s.push_back('0');
	for (int i = l; i < r; ++i)
		s.push_back('1');
	for (int i = r; i < n; ++i)
		s.push_back('0');
	cout << "? " << s << endl;
	int a;
	cin >> a;
	int mans2 = (cnt + r - l - a);
	assert(mans2 % 2 == 0);
	return mans2 / 2;
}

int main()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
		s.push_back('0');
	cout << "? " << s << endl;
	cin >> cnt;
	int mem = get(0, 1);
	auto get1 = [&](int l, int r)
	{
		if (!mem)
			return get(l, r);
		else
			return r - l - get(l, r);
	};
	int L = 0, R = n;
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		if (get1(0, M) >= 1)
			R = M;
		else
			L = M;
	}
	int ans = L;
	if (mem)
		cout << "! " << ans + 1 << ' ' << 1 << endl;
	else
		cout << "! " << 1 << ' ' << ans + 1 << endl;
}