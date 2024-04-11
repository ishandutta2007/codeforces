#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
mt19937 rnd(time(nullptr));
//#define int long long
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
struct edge {
	int h, max;
};
vector<edge>t;
void push(int v) {
	t[v + v].h += t[v].h;
	t[v + v + 1].h += t[v].h;
	t[v + v + 1].max += t[v].h;
	t[v + v].max += t[v].h;
	//t[v].max += t[v].h;
	t[v].h = 0;
}
void upd(int v, int tl, int tr, int l, int r, int x) {
	if (l >= r) {
		return;
	}
	if (tl == l && tr == r) {
		t[v].h += x;
		t[v].max += x;
	}
	else {
		int tm = (tl + tr) / 2;
		push(v);
		upd(v + v, tl, tm, l, min(tm, r), x);
		upd(v + v + 1, tm, tr, max(l, tm), r, x);
		t[v].max = max(t[v + v].max, t[v + v + 1].max);
	}
}
int getma(int v, int tl, int tr, int l, int r) {
	if (l >= r) {
		return -1e9;
	}
	if (tl == l && tr == r) {
		push(v);
		return t[v].max;
	}
	int tm = (tl + tr) / 2;
	push(v);
	return max(getma(v + v, tl, tm, l, min(tm, r)), getma(v + v + 1, tm, tr, max(l, tm), r));
}
signed main() {
	int n;
	cin >> n;
	t.resize(4 * n);
	vector<int>a(n), b(n);
	forn(i, n) {
		cin >> a[i];
		a[i]--;
		b[a[i]] = i;
	}
	vector<int>q(n);
	int ans = n - 1;
	forn(i, n) {
		cin >> q[i];
		q[i] --;
	}
	upd(1, 0, n, 0, b[n - 1] + 1, 1);
	forn(i, n - 1) {
		cout << ans  + 1 << " ";
		upd(1, 0, n, 0, q[i] + 1, -1);
		//cout << getma(1, 0, n, b[ans], b[ans] + 1) << '\n';
		while (t[1].max <= 0) {
			upd(1, 0, n, 0, b[ans - 1] + 1, 1);
			ans--;
		}
	}
	cout << ans + 1;
	return 0;
}