#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 15;
long long a[N];

void fwt_and(long long *arr, int n, int flag) {
	for (int i = 1; i << 1 <= n; i <<= 1)
		for (int j = 0; j < n; j += i << 1)
			for (int k = 0; k < i; ++k)
				arr[j + k] = arr[j + k] + arr[i + j + k] * flag;
}

long long f[200005];

int popcount(long long x) {
	int cnt = 0;
	while (x) {
		if (x & 1) ++cnt;
		x >>= 1;
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, p;
	cin >> n >> m >> p;
	mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, n - 1);
	for (int i = 0; i < n; ++i) {
		long long x = 0;
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] - '0') x |= 1ll << j;
		}
		f[i] = x;
	}
	long long s = 0;
	for (int i = 0; i < 50; ++i) {
		long long g = f[dist(rnd)];
		vector<int> v;
		for (int j = 0; j < m; ++j) {
			if (g & 1ll << j) v.push_back(j);
		}
		int d = v.size();
		memset(a, 0, sizeof a);
		for (int j = 0; j < n; ++j) {
			long long x = 0;
			for (int k = 0; k < d; ++k) {
				if (f[j] & 1ll << v[k]) x |= 1ll << k;
			}
			++a[x];
		}
		fwt_and(a, 1ll << d, 1);
		for (int j = 0; j < 1ll << d; ++j) {
			if (a[j] >= (n + 1) / 2 && popcount(j) > popcount(s)) {
				long long x = 0;
				for (int k = 0; k < d; ++k) {
					if (j & 1ll << k) x |= 1ll << v[k];
				}
				s = x;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		if (s & 1ll << i) cout << 1;
		else cout << 0;
	}
	return 0;
}