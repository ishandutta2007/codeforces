#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;
int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int n, m;
vector<int> a, b;

void read() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	b.resize(m);
	for (auto &i : b) cin >> i;
}

void no() {
	cout << 0 << endl;
	exit(0);
}

int ans;

void run() {
	if (*min_element(all(a)) < *min_element(all(b))) no();
	map<int, int> last;
	for (int i = 0; i < n; i++) {
		last[a[i]] = i;
	}
	for (auto i : b) {
		if (!last.count(i)) no();
	}
	for (int i = 0; i + 1 < m; i++) {
		if (last[b[i]] > last[b[i + 1]]) no();
	}
	vector<int> suffMin = a;
	for (int i = n - 2; i >= 0; i--) {
		chkmin(suffMin[i], suffMin[i + 1]);
	}
	for (int i = 0; i < m; i++) {
		if (suffMin[last[b[i]]] < b[i]) no();
	}
	ans = 1;
	for (int i = 0; i + 1 < m; i++) {
		int pos = last[b[i]] + 1;
		while (suffMin[pos] < b[i + 1]) pos++;
		pos--;
		ans = mul(ans, last[b[i + 1]] - pos);
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