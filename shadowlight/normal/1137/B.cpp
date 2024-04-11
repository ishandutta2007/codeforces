#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> zfunc(string &s) {
	int n = s.size();
	vector <int> z(n, 0);
	int l = -1, r = -1;
	for (int i = 1; i < n; i++) {
		if (r >= i) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int pos = m;
	auto z = zfunc(t);
	for (int i = 1; i < m; i++) {
		if (z[i] == m - i) {
			pos = i;
			break;
		}
	}
	vector <int> cnt(2, 0);
	for (int i = 0; i < n; i++) {
		cnt[s[i] - '0']++;
	}
	vector <int> nt(2, 0);
	for (int i = 0; i < m; i++) {
		nt[t[i] - '0']++;
	}
	vector <int> nl(2, 0);
	for (int i = m - pos; i < m; i++) {
		nl[t[i] - '0']++;
	}
	string res = "";
	if (cnt[0] >= nt[0] && cnt[1] >= nt[1]) {
		res += t;
		cnt[0] -= nt[0];
		cnt[1] -= nt[1];
		while (cnt[0] >= nl[0] && cnt[1] >= nl[1]) {
			res += t.substr(m - pos, m);
			cnt[0] -= nl[0];
			cnt[1] -= nl[1];
		}
	}
	while (cnt[0]) {
		res += '0';
		cnt[0]--;
	}
	while (cnt[1]) {
		res += '1';
		cnt[1]--;
	}
	cout << res << "\n";
}