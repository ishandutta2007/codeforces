#include <bits/stdc++.h>

using namespace std;
const int hmod = 1e9 + 7;
const int hpow = 31;
const int mod = 1e9 + 7;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= hmod;
	while (b) {
		if (b & 1)
			res = res * a % hmod;
		b >>= 1;
		a = a * a % hmod;
	}
	return res;
}

long long inv(long long n) {
	return quickpow(n, hmod - 2);
}

const int ihpow = inv(hpow);

string s[100005];
vector<int> h[100005];
vector<pair<int, int>> v[100005];

int getHash(int x, int y, int z) {
	if (z < y) return h[x][z];
	if (!y) return 1ll * (h[x][z + 1] - h[x][0]) * ihpow % hmod;
	return (h[x][y - 1] + 1ll * (h[x][z + 1] - h[x][y] + hmod) % hmod * ihpow) % hmod;
}

bool comp(int x1, int y1, int x2, int y2) {
	int l = 0, r = min(s[x1].length() - 1 - (y1 < s[x1].length()), s[x2].length() - 1 - (y2 < s[x2].length())), p = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (getHash(x1, y1, m) == getHash(x2, y2, m)) l = m + 1;
		else p = m, r = m - 1;
	}
	if (p == -1) {
		if (s[x1].length() - (y1 < s[x1].length()) == s[x2].length() - (y2 < s[x2].length())) return x1 < x2;
		return s[x1].length() - (y1 < s[x1].length()) < s[x2].length() - (y2 < s[x2].length());
	}
	return s[x1][p + (p >= y1)] < s[x2][p + (p >= y2)];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int len = s[i].length();
		h[i].resize(len);
		h[i][0] = s[i][0] - 'a';
		for (int j = 1; j < len; ++j) {
			h[i][j] = (h[i][j - 1] + (s[i][j] - 'a') * quickpow(hpow, j)) % hmod;
		}
	}
	for (int i = 0; i < n; ++i) {
		v[i].resize(s[i].length() + 1);
		vector<char> nxt(s[i].length());
		nxt[s[i].length() - 1] = 0;
		for (int j = (int) s[i].length() - 2; j >= 0; --j) {
			if (s[i][j] == s[i][j + 1]) nxt[j] = nxt[j + 1];
			else nxt[j] = s[i][j + 1];
		}
		int l = 0, r = s[i].length();
		for (int j = 0; j < s[i].length(); ++j) {
			if (s[i][j] < nxt[j]) v[i][r--] = pair<int, int>(j, i == 0);
			else v[i][l++] = pair<int, int>(j, i == 0);
		}
		v[i][l] = pair<int, int>(s[i].length(), i == 0);
	}
	for (int i = 0; i < n - 1; ++i) {
		int p = 0;
		long long sum = 0;
		for (auto &j: v[i + 1]) {
			while (p < v[i].size() && comp(i, v[i][p].first, i + 1, j.first))
				sum = (sum + v[i][p++].second) % mod;
			j.second = sum;
		}
	}
	long long ans = 0;
	for (auto i: v[n - 1]) {
		ans = (ans + i.second) % mod;
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}