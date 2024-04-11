#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

bool check(string s) {
	set<string> a = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	return a.count(s);
}

void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		string now = "";
		for (int j = i; j < s.size(); j++) {
			now += s[j];
			cnt += check(now);
		}
	}
	if (cnt == 1) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}