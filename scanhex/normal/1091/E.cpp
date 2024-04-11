#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

#ifdef ONPC
const int LG = 10;
#else
const int LG = 20;
#endif
const int N = 1 << LG;

struct it
{
	nagai t[2 * N];
	nagai psh[2 * N];
	it()
	{
		 fill(t, t + 2 * N, 0);
		 fill(psh, psh + 2 * N, 0);
	}
	void push1(int x)
	{
		psh[2 * x] += psh[x];
		t[2 * x] += psh[x];
		psh[2 * x + 1] += psh[x];
		t[2 * x + 1] += psh[x];
		psh[x] = 0;
	}
	void push(int x)
	{
		for (int i = LG; i > 0; --i)
			push1(x >> i);
	}
	void update(int x)
	{
		while (x > 1)
			t[x >> 1] = min(t[x], t[x ^ 1]), x >>= 1;
	}
	void add(int l, int r, nagai val)
	{
		if (l >= r)
			return;
		l += N;
		r += N;
		int l1 = l, r1 = r - 1;
		push(l);
		push(r - 1);
		while (l < r)
		{
			 if (l & 1)
			 {
				 t[l] += val, psh[l] += val;
				 l++;
			 }
			 if (r & 1)
			 {
				 t[r - 1] += val, psh[r - 1] += val;
				 --r;
			 }
			 l /= 2, r /= 2;
		}
		push(l1);
		push(r1 - 1);
		update(l1);
		update(r1 - 1);
	}
	nagai get(int l, int r)
	{
		l += N;
		r += N;
		push(l);
		push(r - 1);
		nagai ans = 0;
		while (l < r)
		{
			if (l & 1)
				ans = min(ans, t[l++]);
			if (r & 1)
				ans = min(ans, t[--r]);
			l /= 2, r /= 2;
		}
		return ans;
	}
	void print()
	{
#ifndef ONPC
		return;
#endif
		for (int i = 0; i < 10; ++i)
		{
			push(N + i);
			cerr << t[N + i] << ' ';
		}
		cerr << '\n';
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<nagai> a(n);
	for (auto& x : a)
		cin >> x;
	nagai s = accumulate(a.begin(), a.end(), 0LL);
	a.push_back(0);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	n++;
	it myit;
	nagai sm = 0;
	vector<nagai> pref(n + 1);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];
	for (nagai k = 1; k <= n - 1; ++k)
	{
		sm += a[k - 1];
		int L = k - 1, R = n; 
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			if (a[M] <= k)
				R = M;
			else
				L = M;
		}
		nagai cnt = R - k;
		nagai val = k * (k - 1) - sm + pref.back() - pref[R] + cnt * k;
		myit.add(k, k + 1, val);
	}
	int ptr = n - 1;
	vector<int> ans;
	for (int i = 0; i <= n; ++i)
	{
		myit.print();
		if ((s + i) % 2 == 0 && myit.get(1, n) >= 0)
			ans.push_back(i);
		while (ptr > 0 && a[ptr - 1] == a[ptr])
			--ptr;
		a[ptr]++;
		myit.add(ptr + 1, n, -1);
		myit.add(a[ptr], n, 1);
	}
	if (ans.size() == 0)
		cout << -1 << '\n';
	else
	{
		for (auto& x : ans)
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}