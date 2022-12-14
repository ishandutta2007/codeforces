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

const int N = (int) 3e5 + 5, sq = 720, mod = (int) 0;
int val[N], sz, mark[N], rev[N], sum[N / sq + 2][N], cnt[N], a[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		cnt[a[j]]++;
	}
	for (int x = 0; x < N; ++x) {
		if (cnt[x] >= sq) {
			mark[x] = 1;
			rev[x] = sz;
			val[sz] = x;
			for (int j = 0; j < n; ++j)
				sum[sz][j + 1] = sum[sz][j] + (a[j] == x);
			sz++;
		}
	}
	memset(cnt, 0, sizeof cnt);
	map<pair<pair<int, int>, int>, int> sv;
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		auto cur = mp(mp(l, r), k);
		if (sv.find(cur) != sv.end()) {
			cout << sv[cur] << '\n';
			continue;
		}
		--l;
		int res = n + 1;
		int want = (r - l) / k + 1;
		if (want < sq) {
			for (int j = l; j < r; ++j) {
				cnt[a[j]]++;
				if (cnt[a[j]] >= want) {
					res = min(res, a[j]);	
				}
			}
			for (int j = l; j < r; ++j) cnt[a[j]] = 0;
		} else {
			
			for (int j = 0; j < sz; ++j) {
				if (sum[j][r] - sum[j][l] >= want) {
					res = min(res, val[j]);	
				}
			}
		}
		cout << (sv[cur] = (res > n ? -1 : res)) << '\n';
	}
}