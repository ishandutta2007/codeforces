#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6  + 10;

int n;
string lett, s;
int q;

void solve() {
	cin >> lett >> s;
	set<char> good;
	for (auto i : lett) good.insert(i);
	n = s.size();
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			pos = i;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		string need;
		cin >> need;
		if (pos == -1) {
			if (need.size() != s.size()) {
				cout << "NO\n";
				continue;
			}
			bool ans = true;
			for (int i = 0; i < n; i++) {
				if (s[i] == '?' && !good.count(need[i])) {
					ans = false;
				}
				if (s[i] != '?' && s[i] != need[i]) {
					ans = false;
				}
			}
			if (ans) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			if ((int)need.size() < n - 1) {
				cout << "NO\n";
				continue;
			}
			bool ans = true;
			for (int i = 0; i < pos; i++) {
				if (s[i] == '?' && !good.count(need[i])) {
					ans = false;
				}
				if (s[i] != '?' && s[i] != need[i]) {
					ans = false;
				}	
			}
			for (int i = (int)need.size() - 1, j = n - 1; j > pos; i--, j--) {
				if (s[j] == '?' && !good.count(need[i])) {
					ans = false;
				}
				if (s[j] != '?' && s[j] != need[i]) {
					ans = false;
				}	
			}
			for (int i = pos; i < pos + (int)need.size() - n + 1; i++) {
				//cout << i << endl;
				assert(i >= 0 && i < (int) need.size());
				if (good.count(need[i])) {
					ans = false;
				}
			}
			if (ans) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
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


/*
c
*
1
bbc

*/