#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
int n;
vector<int> a;
void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

bool ans;

void run() {
	ans = false;
	int pos = 0, m = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > m) {
			pos = i;
			m = a[i];
		}
	}

	set<int> help;
	for (auto i : a)
		help.insert(i);
	if (help.size() != n) {
		return;
	}

	for (int i = pos + 1; i < n; i++) {
		if (a[i] >= a[i - 1])
			return;
	}

	for (int i = pos - 1; i >= 0; i--) {
		if (a[i] >= a[i + 1])
			return;
	}

	ans = true;
}

void write() {
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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