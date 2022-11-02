#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	auto b = a;
	for (auto &i : b) {
		if (i % 2) {
			i = (i - 1) / 2;
		}
		else {
			i = i / 2;
		}
	}

	int sum = 0;
	for (auto i : b)
		sum += i;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) continue;
		if (sum == 0) continue;
		if (sum < 0) {
			b[i]++;
			sum++;
		}
	}
	assert(sum == 0);
	for (auto i : b)
		cout << i << "\n";
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