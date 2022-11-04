#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define len(v) ((int)v.size())
#define pb push_back

typedef long long ll;
typedef long double ld;

vector<int> arr;
int n;

vector<int> calc_lis(const vector<int> &a)
{
	vector<int> ans(len(a), 0);
	vector<int> d(len(a) + 1, 2000000000);
	d[0] = -2000000000;
	for (int i = 0; i < len(a); ++i)
	{
		int k = (int)(upper_bound(all(d), a[i]) - d.begin());
		d[k] = a[i];
		ans[i] = k;
	}
	return ans;
}

vector<int> calc_rev_lis(const vector<int> &a)
{
	vector<int> b = a;
	reverse(all(b));
	b = calc_lis(b);
	reverse(all(b));
	return b;
}

void input()
{
	int m;
	cin >> m >> n;
	vector<pair<int, int>> seg(m);
	for (auto &x : seg)
	{
		cin >> x.first >> x.second;
		--x.first, --x.second;
	}
	vector<pair<int, int>> cnt(n);
	for (auto &x : seg)
	{
		++cnt[x.first].first;
		++cnt[x.second].second;
	}
	arr.resize(n);
	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		cur += cnt[i].first;
		arr[i] = cur;
		cur -= cnt[i].second;
	}
}

int main()
{
	input();
	vector<int> d1 = calc_lis(arr), d2 = calc_rev_lis(arr);
	int mx = 0;
	for (int i = 0; i < n; ++i)
		if (d1[i] + d2[i] > mx)
			mx = d1[i] + d2[i];
	cout << mx - 1 << endl;
	// int n;
	// cin >> n;
	// vector<int> arr(n);
	// for (auto &x : arr)
	// 	cin >> x;
	// for (auto x : calc_lis(arr))
	// 	cout << x << " ";
	// cout << endl;
}