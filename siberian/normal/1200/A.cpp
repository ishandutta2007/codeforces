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
}

vector<int> ans;

void run() {
	ans.resize(10);
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		if (x == 'L') {
			for (int j = 0; j < 10; j++) {
				if (ans[j] == 0) {
					ans[j] = 1;
					break;
				}
			}
		}
		else if (x == 'R') {
			for (int j = 9; j >= 0; j--) {
				if (ans[j] == 0) {
					ans[j] = 1;
					break;
				}
			}
		}
		else {
			ans[x - '0'] = 0;
		}
	}
}

void write() {
	for (auto i : ans)
		cout << i;
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