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
const int N = (int) 0, mod = (int) 0;

int32_t main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int bl = 0, br = n - 1;
		while (bl < br - 1) {
			int bm = bl + br >> 1;	
			int cut_edges = n - 1 - bm;
			int others = (bm + 1) * bm / 2;
			if (others >= cut_edges) {
				br = bm;
			} else {
				bl = bm;
			}
		}
		int res = 0;
		for (int bm = br; bm >= max(0LL, br - 100); --bm) {
			int cut_edges = n - 1 - bm;
			int others = min(cut_edges, (bm + 1) * bm / 2);
			res = max(res, others + cut_edges);
		}
		cout << res << endl;
	}
}