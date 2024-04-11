#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> ra;
vector<int> rb;

void read() {
	cin >> n;
	ra.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		ra[x] = i;
	}
	rb.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		rb[x] = i;
	}
}

int ans;

void run() {
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[ra[i] - rb[i]]++;
		cnt[ra[i] - rb[i] + n]++;
		cnt[ra[i] - rb[i] - n]++;
	}
	ans = 0;
	for (auto i : cnt) {
		chkmax(ans, i.second);
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}