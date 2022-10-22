#include <bits/stdc++.h>

using namespace std;

using nagai = long long;

int main()
{
	ios::sync_with_stdio(false);
	nagai n, l;
	cin >> n >> l;
	vector<nagai> a(n);
	for (auto& x : a)
		cin >> x;
	vector<nagai> b(n);
	for (auto& x : b)
		cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	nagai L = -1, R = l;
	auto dist = [&](nagai a, nagai b)
	{
		if (a > b)
			swap(a, b);
		return min(b - a, a + l - b);
	};
	vector<nagai> b1;
	for (auto x : b)
		b1.push_back(x - l);
	for (auto x : b)
		b1.push_back(x);
	for (auto x : b)
		b1.push_back(x + l);
	while (R - L > 1)
	{
		nagai M = L + R >> 1;
		vector<pair<int, int>> segs;
		bool bad = false;
		int cntok = 0;
		for (int i = 0; i < n; ++i)
		{
			int firstbad, firstgood;
			firstbad = upper_bound(b1.begin(), b1.end(), a[i] + M) - b1.begin();
			firstgood = lower_bound(b1.begin(), b1.end(), a[i] - M) - b1.begin();
			if (firstbad - firstgood >= n)
			{
				++cntok;
				continue;
			}
			segs.emplace_back(firstgood - i, firstbad - i);
		}
		int n1 = 3 * n; 
		vector<int> add(2 * n1);
		vector<pair<int, int>> segs1;
		for (auto x : segs)
		{
			if (0 <= x.first && x.second < 2 * n1)
				segs1.emplace_back(x.first, x.second);
			if (0 <= x.first + n1 && x.second + n1 < 2 * n1)
				segs1.emplace_back(x.first + n1, x.second + n1);
		}
		segs.swap(segs1);
		for (auto& x : segs)
		{
			++add[x.first];
			if (x.second < 2 * n1)
				--add[x.second];
		}
		bool ok = false;
		int cur = 0;
		vector<int> ansich(2 * n);
		for (int i = 0; i < add.size(); ++i)
		{
			cur += add[i];
			int mem = i / n1;
			ansich[i % n + mem * n] += cur;
		}
		if (*max_element(ansich.begin(), ansich.end()) >= n - cntok)
			R = M;
		else
			L = M;
	}
	cout << R << '\n';
}