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

	int get(int pos, int x) {
		int ans = 0;
		//cout << "pos = " << pos << " x = " << x << endl;
		for (int i = pos; i < pos + k; i += 3)
			ans += (s[i] != help[x]);
		
		x = (x + 1) % 3;
		pos++;

		for (int i = pos; i < pos - 1 + k; i += 3)
			ans += (s[i] != help[x]);
		
		x = (x + 1) % 3;
		pos++;

		for (int i = pos; i < pos - 2 + k; i += 3)
			ans += (s[i] != help[x]);
		//cout << "pos = " << pos << " x = " << x << " ans = " << ans << endl;
		return ans;
	}

	int get(int pos) {
		int ans = 1e9;
		for (auto i : help)
			chkmin(ans, get(pos, i.first));
		return ans;
	}

	int get() {
		int ans = 1e9;
		for (int i = 0; i + k - 1 < n; i++)
			chkmin(ans, get(i));
		return ans;
	}
}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	//cout << n << " " << k << " " << s << endl;
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