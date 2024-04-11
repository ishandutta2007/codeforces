#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define inf 2000000000
#define mod 1000000009

ll pw[15];

void useFiles(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

ll get_substr(ll v, int l, int r)
{
	r -= l;
	v /= pw[l];
	v %= pw[r];
	v += pw[r];
	return v;
}

int get_len(ll v)
{
	int cnt = 0;
	while (v)
	{
		v /= 10;
		++cnt;
	}
	return cnt;
}

ll count(ll num, ll hash)
{
	int n = get_len(hash) - 1, cnt = 0;
	for (int i = 0; i < 9 - n + 1; ++i)
		if (get_substr(num, i, i + n) == hash)
			++cnt;
	return cnt;
}


void init()
{
	pw[0] = 1;
	for (int i = 1; i < 15; ++i)
		pw[i] = pw[i - 1] * 10;
}

int main()
{
	init();
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;
	map<ll, int> mp;
	for (auto &x : a)
		for (int l = 0; l < 9; ++l)
			for (int r = l + 1; r < 10; ++r)
			{
				auto v = get_substr(x, l, r);
				if (!mp.count(v))
					mp[v] = 0;
				++mp[v];
			}
	for (auto &x : a)
	{
		ll mn = 1000000000000;
		for (int l = 0; l < 9; ++l)
			for (int r = l + 1; r < 10; ++r)
			{
				auto v = get_substr(x, l, r);
				int k = count(x, v);
				if (mp[v] - k <= 0)
					mn = min(mn, v);
			}
		cout << to_string(mn).substr(1) << endl;
	}
}