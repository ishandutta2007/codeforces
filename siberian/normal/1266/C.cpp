#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m;

void read() {
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0 << endl;
		exit(0);
	}
}

void run() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (m != 1)
				cout << i * (j + n) << " ";
			else 
				cout << j * (i + m) << " "; 
		}
		cout << endl;
	}
}

void write() {

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