#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m;
vector<int> a, b;
int sum1 = 0, sum2 = 0;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	cin >> m;
	b.resize(m);
	for (auto &i : b)
		cin >> i;
}

void check() {
	int sum1 = 0, sum2 = 0;
	for (auto i : a)
		sum1 += i;
	for (auto i : b)
		sum2 += i;
	if (sum1 != sum2) {
		cout << -1 << endl;
		exit(0);
	}
}

int ans;

void run() {
	check();
	ans = 0;
	int sum1 = 0, sum2 = 0;
	int pos1 = 0, pos2 = 0;
	while (pos1 < n || pos2 < m) {
		if (pos1 == n) {
			sum2 += b[pos2++];
		}
		else if (pos2 == m) {
			sum1 += a[pos1++];
		}
		else {
			if (sum1 < sum2) {
				sum1 += a[pos1++];
			}
			else {
				sum2 += b[pos2++];
			}
		}
		if (sum1 == sum2) {
			ans++;
		}
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