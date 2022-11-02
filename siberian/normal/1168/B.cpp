#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
void read() {
	cin >> s;
}

int check(int l, int r) {
	for (int i = 1; r - 2 * i >= l; i++) {
		if (s[r] == s[r - i] && s[r] == s[r - 2 * i]) {
			return true;
		}
	}
	return false;
}

int ans;
void run() {
	ans = 0;
	int l = 0, r = 0;
	int n = s.size();
	while (r < n) {
		while (check(l, r)) {
			ans += n - r;
			l++;
		}
		r++;
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