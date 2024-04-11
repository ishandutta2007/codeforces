#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int n;
const int N = 2e5 + 10;
char nxt[N];
bool used[N];

void build() {
	fill(used, used + n, false);
	for (int i = 0; i < n; i++) {
		if (nxt[i] == 'R' && nxt[(i + 1) % n] == 'L') {
			used[i] = true;
			used[(i + 1) % n] = true;
		}
	}
}

int calcComp(int pos, char x) {
	if (used[pos]) return 0;
	int ans = 1;
	used[pos] = true;
	for (int i = 1; ; i++) {
		if (used[(i + pos) % n]) break;
		if (nxt[(i + pos) % n] != x) break;
		ans++;
		used[(i + pos) % n] = true;
	}
	for (int i = 1; ; i++) {
		if (used[(pos - i + n) % n]) break;
		if (nxt[(pos - i + n) % n] != x) break;
		ans++;
		used[(pos - i + n) % n] = true;
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nxt[i];
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		ok &= nxt[i] == nxt[0];
	}
	if (ok) {
		cout << (n + 2) / 3 << "\n";
		return;
	}
	build();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (calcComp(i, nxt[i]) + 1) / 3;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}