#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}
#define int ll

int n, k;
bool ans;
vector<int> a;

int get(vector<int> & a) {
	vector<int> pref(n + 1);
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + (a[i - 1] >= k ? 1 : -1);
	}
	for (int i = 2; i <= n; i++) {
		if (pref[i] - pref[i - 2] >= 1) return i;
		chkmin(pref[i - 1], pref[i - 2]);
	}
	return -1;
}

void solve() {
	cin >> n >> k;
	if (n == 1) {
		int x;
		cin >> x;
		if (x == k) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
		return;
	}
	a.assign(n, 0);
	for (auto &i : a) cin >> i;
	int L = get(a);
	ans = false;
	if (L != -1) {
		for (int i = n - 1; i >= L - 1; i--) {
			if (a[i] == k) {
				ans = true;
			}
		}
	}
	reverse(all(a));
	L = get(a);
	if (L != -1) {
		for (int i = n - 1; i >= L - 1; i--) {
			if (a[i] == k) {
				ans = true;
			}
		}
	}
	if (ans) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}