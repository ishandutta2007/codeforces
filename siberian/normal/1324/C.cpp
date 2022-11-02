#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
string s;

bool check(int d) {
	int pos = d;
	int last = -1;
	while (pos <= n) {
		//cout << "pos = " << pos << endl;
		if (s[pos - 1] == 'R') {
			last = pos;
			pos += d;
			continue;
		}
		bool flag = false;
		for (int i = pos - 1; i >= max(pos - 1 - d, last + 1); i--) {
			if (s[i - 1] == 'R') {
				pos = i;
				last = pos;
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}

void solve() {
	cin >> s;
	n = s.size();
	//check(3);
	//exit(0);
	int l = 0, r = n + 2;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}