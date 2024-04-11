#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int calc(vector<int> a) {
	int ans = 0;
	for (int i = 0; i < (int)a.size(); i += 2) {
		ans += a[i];
	}
	return ans;
}

void stupidSolve(vector<int> a) {
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i; j < (int)a.size(); j++) {
			reverse(a.begin() + i, a.begin() + j + 1);
			if (calc(a) == 37) {
				cout << "i = " << i << " j = " << j << endl;
			}

			reverse(a.begin() + i, a.begin() + j + 1);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	//stupidSolve(a);
	vector<int> prefEven(n, 0), prefOdd(n, 0), suffOdd(n, 0);
	for (int i = 0; i < n; i++) {
		if (i > 0) prefEven[i] = prefEven[i - 1], prefOdd[i] = prefOdd[i - 1];
		if (i % 2 == 0) prefOdd[i] += a[i];
	    else prefEven[i] += a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i + 1 < n) suffOdd[i] = suffOdd[i + 1];
		if (i % 2 == 0) suffOdd[i] += a[i];
	}
	/*for (auto i : prefEven) cout << i << " ";
	cout << endl;
	for (auto i : prefOdd) cout << i << " ";
	cout << endl;
	for (auto i : suffOdd) cout << i << " ";
	cout << endl;*/
	int ans = prefOdd[n - 1];
	int mx = 0;
	for (int i = 0; i < n; i += 2) {
		int fans = 0;
		if (i + 1 < n) fans += suffOdd[i + 1];
		fans += prefEven[i];
		fans += mx;
		chkmax(ans, fans);
		chkmax(mx, prefOdd[i] - prefEven[i]);
	}
	mx = 0;
	for (int i = 1; i < n; i += 2) {
		int fans = 0;
		if (i + 1 < n) fans += suffOdd[i + 1];
		fans += prefEven[i];
		fans += mx;
		chkmax(ans, fans);
		chkmax(mx, prefOdd[i] - prefEven[i]);
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}