#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void read() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		if (s.size() == 1) {
			cout << n << "\n";
		} else {
			cout << 1 << "\n";
		}
	}
}

void run() {

}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}