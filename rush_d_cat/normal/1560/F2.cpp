#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		string n; int k;
		cin >> n >> k;

		set<char> st;
		for (int i = 0; n[i]; i ++) st.insert(n[i]);
		if (st.size() <= k) {
			cout << n << endl; continue;
		}
		auto toInt = [](string s) {
			ll ans = 0;
			for (int i = 0; s[i]; i ++)
				ans = ans * 10L + s[i] - '0';
			return ans;
		};
		auto mn = [&](string s, string t) {
			return toInt(s) < toInt(t) ? s : t;
		};

		string ans = "";
		if (k == 1) {
			ans = "1";
			for (int i = 0; i < n.length(); i ++) ans += "1";
		} else {
			ans = "1";
			for (int i = 0; i < n.length(); i ++) ans += "0";
		}

		string pref = "";
		for (int i = 0; i < n.length(); i ++) {
			for (char c = n[i] + 1; c <= '9'; c ++) {
				string tmp = pref; tmp += c;
				set<char> st;
				for (auto ch: tmp) st.insert(ch);
				if (st.size() > k) continue;
				char nex = st.size() == k ? (*st.begin()) : '0';
				for (int pos = i + 1; pos < n.length(); pos ++)
					tmp += nex;
				ans = mn(ans, tmp);
			}
			pref += n[i];
		}
		cout << ans << "\n";
	}
}