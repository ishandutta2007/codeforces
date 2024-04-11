#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 1 << 20;

struct it
{
	pair<int, int> t[2 * N];
	it()
	{
		for (int i = 2 * N - 1; i >= 0; --i)
			if (i >= N)
				t[i] = {0, i - N};
			else 
				t[i] = t[i * 2];
	}
	pair<int, int> get(int l, int r)
	{
		l += N;
		r += N;
		pair<int, int> ans = {0, 0};
		while (l < r)
		{
			 if (l & 1)
				 ans = max(ans, t[l++]);
			 if (r & 1)
				 ans = max(ans, t[--r]);
			 l /= 2, r /= 2;
		}
		return ans;
	}
	void st(int x, int y)
	{
		x += N;
		t[x] = {y, x - N};
		while (x)
			t[x >> 1] = max(t[x], t[x ^ 1]), x >>= 1;
	}
};
vector<int> arr;

nagai ans = 0;
nagai mod = 1e9 + 7;

it myit;

vector<nagai> cnt;

int n, k;

void solve(int l, int r)
{
	if (r - l < k)
		return;
	auto p = myit.get(l, r);
	int val = p.first;
	int ind = p.second;
	nagai c = cnt[r - l];
	c -= cnt[r - (ind + 1)];
	c -= cnt[ind - l];
	c %= mod;
	ans += val * c;
	ans %= mod;
	solve(l, ind);
	solve(ind + 1, r);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	arr.resize(n);
	for (auto& x : arr)
		cin >> x;
	for (int i = 0; i < n; ++i)
		myit.st(i, arr[i]);
	cnt.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		nagai L = 0, R = n + 5;
		while (R - L > 1)
		{
			nagai M = (L + R) / 2;
			if (k * M - (M - 1) <= i)
				L = M;
			else
				R = M;
		}
		cnt[i] = cnt[i - 1] + L;
	}
	solve(0, n);
	cout << ans << '\n';
	return 0;
}