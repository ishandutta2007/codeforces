#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void read() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	int add = 0;
	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos, val;
			cin >> pos >> val;
			pos--;
			a[pos] = val - add;
		}
		if (t == 2) {
			int val;
			cin >> val;
			add += val;
		}
		if(t == 3) {
			int pos;
			cin >> pos;
			pos--;
			cout << a[pos] + add << "\n";
		} 
	}
}

void run() {

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