#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	vector<nagai> a(n), b(m);
	for (auto& x : a)
		scanf("%lld", &x);
	for (auto& y : b)
		scanf("%lld", &y);
	nagai suma = 0;
	for (int i = 0; i < n; ++i)
		suma += (1 - (i & 1) * 2) * a[i];
	vector<nagai> mems;
	nagai cur = 0;
	for (int i = 0; i < n; ++i)
		cur += ((i & 1) * 2 - 1) * b[i];
	mems.push_back(cur);
	for (int i = n; i < m; ++i)
	{
		cur += b[i - n];
		cur = -cur;
		if (n & 1)
			cur -= b[i];
		else
			cur += b[i];
		mems.push_back(cur);
	}
	sort(mems.begin(), mems.end());
	auto get = [&](nagai x)
	{
		int ind = lower_bound(mems.begin(), mems.end(), x) - mems.begin();
		nagai ans = 1e18;
		if (ind < mems.size())
			ans = mems[ind] - x;
		if (ind > 0)
			ans = min(ans, x - mems[ind - 1]);
		return ans;
	};
	cout << get(-suma) << endl;
	for (int i = 0; i < q; ++i)
	{
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		--l;
		if (r - l & 1)
			if (r & 1)
				suma += x;
			else
				suma -= x;
		cout << get(-suma) << endl;
	}
}