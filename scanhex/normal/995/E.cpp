#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int u, v, p;

int mult(int a, int b)
{
	return 1LL * a * b % p;
}

int pw(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = mult(ans, a);
		a = mult(a, a);
		b >>= 1;
	}
	return ans;
}

int inv(int a)
{
	return pw(a, p - 2);
}

struct st
{
	int start, d, from;
};

unordered_map<int, st> mem;
vector<int> au, av;

int md(int x)
{
	if (x < 0)
		return x + p;
	if (x >= p)
		return x - p;
	return x;
}
vector<int> q;

void go(int x, int a, int b, int from)
{
	if (mem.count(x))
		return;
	mem[x] = {a, b, from};
	q.push_back(x);
}

int go1(int x)
{
	return md(x + 1);
}
int go2(int x)
{
	return md(x - 1);
}
vector<int> restore(int x)
{
	vector<int> ans;
	while (mem[x].d > 0)
		ans.push_back(x), x = mem[x].from;
	ans.push_back(x);
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	cin >> u >> v >> p;
	if (u == v)
	{
		cout << 0 << '\n';
		return 0;
	}
	mem.rehash(1000000);
	mem[u] = {u, 0};
	mem[v] = {v, 0};
	q.push_back(u);
	q.push_back(v);
	for (int i = 0; i < q.size() && i < 1000000; ++i)
	{
		int x = q[i];
		auto p = mem[x];
		go(md(x - 1), p.start, p.d + 1, x);
		go(md(x + 1), p.start, p.d + 1, x);
		go(inv(x), p.start, p.d + 1, x);
	}
	vector<pair<int, st>> arr;
	for (int x : q)
		arr.emplace_back(x, mem[x]);
	sort(arr.begin(), arr.end(), [&](pair<int, st>& a, pair<int, st>& b)
			{
			return a.first < b.first;
			});
	for (int i = 0; i + 1 < arr.size(); ++i)
	{
		auto x = arr[i];
		auto y = arr[i + 1];
		if (x.second.start == y.second.start)
			continue;
		if (x.second.d + y.second.d + abs(x.first - y.first) <= 200)
		{
			if (x.second.start == v)
				swap(x, y);
			auto mem = restore(x.first);
			auto kek = restore(y.first);
			reverse(kek.begin(), kek.end());
			vector<int> ans;
			for (int i = 0; i + 1 < mem.size(); ++i)
				if (go1(mem[i]) == mem[i + 1])
					ans.push_back(1);
				else if (go2(mem[i]) == mem[i + 1])
					ans.push_back(2);
				else
					ans.push_back(3);
			int lol = x.first - y.first;
			for (int i = 0; i < abs(lol); ++i)
				ans.push_back(lol > 0 ? 2 : 1);
			for (int i = 0; i + 1 < kek.size(); ++i)
				if (go1(kek[i]) == kek[i + 1])
					ans.push_back(1);
				else if (go2(kek[i]) == kek[i + 1])
					ans.push_back(2);
				else
					ans.push_back(3);
			cout << ans.size() << '\n';
			for (int x : ans)
				cout << x << ' ';
			cout << '\n';
			return 0;
		}
	}
}