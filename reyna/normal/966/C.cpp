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
const int N = (int) 62, mod = (int) 0;
vector<int> hi[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		for (int i = N - 1; i >= 0; --i)
			if (x >> i & 1) {
				hi[i].pb(x);
				break;
			}
	}
	int cur = 0;
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		int did = 0;
		for (int j = 0; j < N; ++j) if ((~cur >> j & 1) && hi[j].size()) {
			did = 1;
			res.pb(hi[j].back());
			cur ^= hi[j].back();
			hi[j].pop_back();
			break;
		}
		if (!did) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for (int j = 0; j < n; ++j) cout << res[j] << ' ';
}