// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = (int) 2e5 + 5, mod = 0;
vector<int> dv[N];

int a[N], last[N], n, mn[N << 2], sum[N << 2], ch[N << 2], suf[N], cnt[N];

void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		mn[v] = sum[v] = suf[b];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	sum[v] = sum[l] + sum[r];
	mn[v] = min(mn[l], mn[r]);
}

void push(int v, int l, int r, int sz1, int sz2) {
	if (ch[v] == -1) return;
	ch[l] = ch[r] = mn[l] = mn[r] = ch[v];
	sum[l] = sz1 * ch[v];
	sum[r] = sz2 * ch[v];
	ch[v] = -1;
}

void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
        if (j <= i) return;
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		ch[v] = x;
		sum[v] = (e - b) * x;
		mn[v] = x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, l, r, m - b, e - m);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	sum[v] = sum[l] + sum[r];
	mn[v] = min(mn[l], mn[r]);
}

int find(int x, int v = 1, int b = 0, int e = n) {
	if (mn[v] >= x) return -1;
	if (b + 1 == e)
		return b;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, l, r, m - b, e - m);
	int ansl = find(x, l, b, m);
	if (ansl != -1)
		return ansl;
	return find(x, r, m, e);
}

int query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return 0;
	if (i <= b && e <= j)
		return sum[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, l, r, m - b, e - m);
	return query(i, j, l, b, m) + query(i, j, r, m, e);
}
int32_t main() {
	memset(ch, -1, sizeof ch);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	rep(i, n)
		cin >> a[i];
	n++;
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			dv[j].push_back(i);
	int mx = 0;
	for (int i = n - 1; i >= 1; --i) {
		suf[i] = mx;
		for (int d : dv[a[i - 1]]) {
			cnt[d]++;
			if (cnt[d] >= 2)
				mx = max(mx, d);
		}
	}
	suf[0] = (int) 1e9;
	memset(cnt, 0, sizeof cnt);
	memset(last, -1, sizeof last);
	build();
	rep(i, n - 1)
		for (auto d : dv[a[i]])
			last[d] = max(last[d], i);
	long long res = 0;
	mx = 0;
	rep(i, n - 1) {
		int r = find(mx);
		if (r == -1)
			r = n;
//		cout << i << ' ' << mx << ' ' << r << endl;
		res += query(i + 1, r) + mx * min(n - i - 1, (n - r));
		int x = a[i];
		for (int d : dv[x]) {
			int pos = find(d);
			if (pos == -1)
				pos = n;
//			cout << pos << ' ' << last[d] + 1 << ' ' << d << " hi " << endl;
			if (last[d] != -1) 
				update(pos, last[d] + 1, d);
			cnt[d]++;
			if (cnt[d] >= 2)
				mx = max(mx, d);
		}
//		cout << i << ' ' << mx << endl;
//		int r = find(mx);
//		res += query(i + 2, r) + mx * min(n - i - 1, (n - r));
	}
	cout << res << endl;
	return 0;
}