// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e6 + 5, base = 1e6 + 3, mod = (int) 1e9 + 7;
vector<int> all[N];
int h[N];
int can[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		int wv = u - v;
		if (u - v < 0) {
			wv += n;
		}
		all[v].pb(wv);
		
		all[u].pb((v - u + n) % n);
	}
	for (int j = 0; j < n; ++j) {
		sort(ALL(all[j]));
		for (int x : all[j])
			h[j] = ((LL) h[j] * base + x) % mod;
	}
	for (int d = 1; d < n; ++d)
		if (n % d == 0) {
			int c = 1;
			for (int v = 0; v < n; ++v)
				if (h[v] != h[(v + d) % n]) {
					c = 0;
				}
			if (c) {
				cout << "Yes\n";
				return 0;
			}
		}
	cout << "No\n";
}