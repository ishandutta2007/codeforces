#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}


string a, b;
int l, r, flag;

char rev(char x) {
	return 1 - (x - '0') + '0';
}

void make(int pos) {
	if (pos == 0) {
		if (!flag) {
			a[l] = rev(a[l]);
		} else {
			a[r] = rev(a[r]);
		}
		return;
	}
	flag ^= 1;
	//for (int i = 0; i <= pos; i++) {
	//	a[i] = ((a[i] - '0') ^ 1) + '0';
	//}
	//reverse(a.begin(), a.begin() + pos + 1);
}

void nxt() {
	if (!flag) r--;
	else l++;
}

char get(int pos) {
	//return a[pos];
	if (!flag) return a[l + pos];
	return rev(a[r - pos]);
}

void solve() {
	int n;
	cin >> n;
	cin >> a >> b;
	l = 0, r = n - 1, flag = 0;
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (get(i) == b[i]) {
			nxt();
			continue;
		}
		if (get(i) == get(0)) {
			make(i);
			ans.push_back(i);
		} else {
			make(0);
			ans.push_back(0);
			make(i);
			ans.push_back(i);
		}
		nxt();
	}
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i + 1 << " ";
	}
	cout << "\n";
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