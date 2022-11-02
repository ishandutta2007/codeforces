#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int readInt() {
	int ans = 0;
	string s;
	cin >> s;
	for (auto i : s) {
		ans *= 2;
		ans += i - '0';
	}
	return ans;
}

string writeInt(int ans, int m) {
	string have = "";
	while (m--) {
		have += ans % 2 + '0';
		ans >>= 1;
	}
	reverse(all(have));
	return have;
}

bool check(int val, vector<int> & bad, int need) {
	auto it = lower_bound(all(bad), val);
	if (it != bad.end() && (*it) == val) return false; 
	int cntL = it - bad.begin();
	//cout << val << " " << cntL << " " << need << endl;
	if (val - cntL == need) return true;
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> bad;
	for (int i = 0; i < n; i++) {
		bad.push_back(readInt());
	}
	sort(all(bad));
	/*cout << "bad = " << endl;
	for (auto i : bad)
		cout << i << " ";
	cout << endl;*/
	int k = (1LL << m) - n;
	int need = (k - 1) / 2;
	//cout << "need = " << need << endl;
	for (int val = max(0LL, need - n - 10); val <= min((1LL << m) - 1, need + n + 10); val++) {
		if (check(val, bad, need)) {
			//cout << "val = " << val << endl; 
			cout << writeInt(val, m) << "\n";
			return;
		}
	}
	assert(false);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}