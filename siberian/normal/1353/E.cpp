#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int cnt0 = 0;
	for (auto i : s) 
		cnt0 += i == '0';
	int cnt1 = n - cnt0;
	//cout << cnt0 << " " << cnt1 << endl;
	int ans = cnt1;
	for (int i = 0; i < k; i++) {
		//if (i == 0) continue;
		// NOOOOOOOOOOOOO
		string fans = "";
		int my_cnt0 = 0, my_cnt1 = 0;
		for (int j = i; j < n; j += k) {
			fans += s[j];
			if (s[j] == '0') my_cnt0++;
			else my_cnt1++;
		}
		//cout << "fans = " << fans << endl;
		int now = 0;
		now += cnt1 - my_cnt1;
		vector<int> pref(fans.size());
		pref[0] = fans[0] == '1';
		int x = my_cnt0;
		for (int j = 1; j < (int)fans.size(); j++) {
			pref[j] = pref[j - 1] + (fans[j] == '1');
		}

		/*cout << "x = " << x << endl;
		cout << "pref = " << endl;
		for (auto j : pref) {
			cout << j << " ";
		}
		cout << endl;*/
		for (int j = (int)fans.size() - 1; j >= 0; j--) {
			int my_ans = 0;
			my_ans += (j > 0 ? pref[j - 1] : 0);
			my_ans -= (j > 0 ? j - pref[j - 1] : 0);
			my_ans += x;
			my_ans += now;
		//	cout << "first = " << (j > 0 ? pref[j - 1] : 0) << " second = " << (j > 0 ? j - pref[j - 1] : 0) << " third = " << x << endl;
			chkmin(ans, my_ans);
		//	cout << "my_ans = " << my_ans << endl;
			chkmin(x, my_cnt1 - (j > 0 ? pref[j - 1] : 0) + j - (j > 0 ? pref[j - 1] : 0));
		}
	}
	cout << ans << "\n";
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