#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
string s;

void read() {
	cin >> s;
	n = s.size();
}

const int MAXN = 2e5 + 10, MAXA = 26;
int pref[MAXN][MAXA];

void build() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAXA; j++) {
			pref[i][j] = pref[i - 1][j];
		}
		pref[i][s[i - 1] - 'a']++;
	}
}

bool check(int l, int r) {
	if (l == r) return true;
	int cnt = 0;
	for (int i = 0; i < MAXA; i++)
		cnt += (pref[r][i] - pref[l - 1][i]) > 0;
	if (cnt == 1) {
		return false;
	}
	if (cnt >= 3) {
		return true;
	}
	return s[l - 1] != s[r - 1];
}

vector<bool> ans;

void run() {
	build();
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		ans.push_back(check(l, r));
	}
}

void write() {
	for (auto i : ans) {
		if (i) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
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