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

const int N = (int) 1e6 + 6, mod = (int) 0;
int p[N], mark[N], a[N], b[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], --a[j];
	for (int j = 0; j < n; ++j) cin >> b[j], --b[j];
	vector<int> imp;
	for (int j = 0; j < n; ++j) {
		if (a[j] != b[j]) {
			imp.push_back(j);
		}
	}
	int cnt = 0;
	for (int j = 0; j < n; ++j)
		if (a[j] == b[j]) {
			p[j] = a[j];
			mark[p[j]] = 1;	
			++cnt;
		}
	if (cnt == n - 1) {
		int pt = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] != b[j]) {
				while (mark[pt]) ++pt;
				p[j] = pt;
			}
		}
		for (int j = 0; j < n; ++j)
			cout << p[j] + 1 << ' ';
	} else {
		int x = -1, y = -1;
		for (int j = 0; j < n; ++j) {
			if (!mark[j]) {
				if (x == -1) {
					x = j;
				} else {
					y = j;
				}
			}
		}
		for (int s = 0; s < n; ++s) {
			if (a[s] != b[s]) {
				for (int d = 0; d < n; ++d) {
					if (s != d && a[d] != b[d]) {
						p[s] = x;
						p[d] = y;
						int ac = 0, bc = 0;
						for (int j = 0; j < n; ++j) {
							ac += (p[j] == a[j]);
							bc += (p[j] == b[j]);
							
						}
						if (ac == n - 1 && bc == n - 1) {
							for (int j = 0; j < n; ++j)
								cout << p[j] + 1 << ' ';
							return 0;
						}
					}
				}
			}
		}
		assert(0);
	}
}