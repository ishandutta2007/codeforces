#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

namespace fget{
	int n, k;
	string s;
	map <int, char> help;
	void make(int n1, int k1, string t) {
		n = n1;
		k = k1;
		s = t;
		help[0] = 'R';
		help[1] = 'G';
		help[2] = 'B';
	}

	int get(string t) {
		vector<int> x(n + 1);
		for (int i = 1; i <= n; i++)
			x[i] = s[i - 1] != t[i - 1];
		for (int i = 1; i <= n; i++)
			x[i] += x[i - 1];
		int ans = 1e9 + 10;
		for (int i = 1; i + k - 1 <= n; i++) {
			ans = min(ans, x[i + k - 1] - x[i - 1]);
		}
		return ans;
	}

	int get() {
		string t = "";
		for (int i = 0; i < n; i++) {
			t += help[i % 3];
		}

		int ans = 1e9;
		chkmin(ans, get(t));

		t = "";
		for (int i = 0; i < n; i++) {
			t += help[(i + 1) % 3];
		}
		chkmin(ans, get(t));

		t = "";
		for (int i = 0; i < n; i++) {
			t += help[(i + 2) % 3];
		}
		chkmin(ans, get(t));

		return ans;
	}
}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	fget::make(n, k, s);
	cout << fget::get() << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}