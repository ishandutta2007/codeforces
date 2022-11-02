#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO";
		exit(0);
	}
}

vector<int> ans;

void run() {
	ans.resize(2 * n);
	for (int i = 0, pos = 0;i < 2 * n; pos++, i += 2) {
		if (pos % 2 == 0) {
			ans[pos] = i;
			ans[pos + n] = i + 1;
		}
		else {
			ans[pos] = i + 1;
			ans[pos + n] = i;
		}
	}
}

void write() {
	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << " ";
	cout << endl;
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