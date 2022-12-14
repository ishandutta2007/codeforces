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
#define int long long
const int N = (int) 3e6 + 6;
int pos[N], res[N], a[N];
vector<int> to_solve[N];
int fpm(int a, int b, int mod) { return b != 0 ? fpm((LL) a * a % mod, b >> 1, mod) * (LL) (b & 1 ? a % mod : 1 % mod) % mod : 1 % mod; }
int32_t main() {
	int mod, n, jump = 0;
	cin >> mod >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		jump = (jump + a[j]) % mod;
		if (j >= 1) {
			a[j] += a[j - 1];
			a[j] %= mod;
		}
	}
	jump %= mod;
	int g = (min(jump, mod) == 0 ? max(jump, mod) : __gcd(jump, mod));
	jump /= g;
	mod /= g;
	map<int, int> rev;
	int cnt = 0;
	for (int j = 0; j < n; ++j) {
		int x = a[j] % g;
		if (rev.find(x) == rev.end()) {
			rev[x] = cnt++;	
		}
		to_solve[rev[x]].push_back(j);
	}
	int phi = mod;
	{
		int tmp = mod;
		for (int j = 2; j * j <= tmp; ++j) {
			if (tmp % j == 0) phi -= phi / j;	
			while (tmp % j == 0) tmp /= j;
		}
		if (tmp != 1) phi -= phi / tmp;
	}
	for (int to = 0; to < cnt; ++to) {
		vector<int> cur = to_solve[to];
		vector<int> val;
		int m = (int) cur.size();
		for (int j = 0; j < m; ++j) val.push_back(a[cur[j]] / g);
		vector<pair<int, int>> all;
		for (int j = 0; j < m; ++j) {
			pos[j] = (LL) (val[j] - val[0] + (int) 1e9 * mod) % mod * fpm(jump, phi - 1, mod) % mod;
			pos[j] %= mod;
			all.push_back(mp(pos[j], -cur[j]));
		}
		sort(all.begin(), all.end());
		for (int i = 0; i < m; ++i) {
			int cur_pos = all[i].x, j = -all[i].y;
			int nxt_pos = all[(i + 1) % m].x + (i + 1) / m * mod;
			res[j] = nxt_pos - cur_pos;
		}
	}
	// : (
	for (int j = 0; j < n; ++j) cout << res[j] << ' ';
}