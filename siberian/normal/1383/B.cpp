#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	int sumXor = 0;
	for (auto i : a) {
		sumXor ^= i;
	}
	if (sumXor == 0) {
		cout << "DRAW" << "\n";
		return;
	}
	//cout << sumXor << endl;
	int cnt0 = 0, cnt1 = 0;
	for (int bit = 32; bit >= 0; bit--) {
		if ((sumXor >> bit) & 1) {
			//cout << "bit = " << bit << endl;
			for (auto i : a) {
				if ((i >> bit) & 1) {
					cnt1++;
				} else {
					cnt0++;
				}
			}
			break;
		} 
	}
	//cout << cnt0 << " " << cnt1 << endl;
	if (cnt1 % 4 == 1 || cnt0 % 2 == 1) {
		cout << "WIN" << "\n";
	} else {
		cout << "LOSE" << "\n";
	}
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