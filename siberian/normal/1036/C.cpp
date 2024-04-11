#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
const int INF = 1e17;

vector<int> a;

void add(int num, int cnt) {
	a.push_back(num);
	if (num > INF) return;
	add(num * 10, cnt);
	if (cnt == 3) {
		return;
	}
	for (int i = 1; i <= 9; i++)
		add(num * 10 + i, cnt + 1);
}

void gen() {
	for (int i = 1; i <= 9; i++)
		add(i, 1);
	sort(a.begin(), a.end());
}

int get(int r) {
	return (--upper_bound(a.begin(), a.end(), r)) - a.begin();
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

void solve() {
	int l, r;
	cin >> l >> r;
	cout << get(l, r) << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	gen();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}