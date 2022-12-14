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

const int N = (int) 1e6 + 6, S = 2005, mod = (int) 0;
int h, have[N], q[N], t, d[N];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int j = 0; j < k; ++j) {
		int x;
		scanf("%d", &x);
		have[x] = 1;
	}
	memset(d, 63, sizeof d);
	for (int j = 0; j < S; ++j)
		if (have[j]) {
			q[t++] = j - n + S;
			d[j - n + S] = 1;
		}
	while (h != t) {
		int v = q[h++];
		for (int j = 0; j < S; ++j) if (have[j]) {
			int nxt = j - n + v;
			if (nxt < 0 || nxt > 2 * S) continue;
			if (d[nxt] > d[v] + 1) {
				d[nxt] = d[v] + 1;
				q[t++] = nxt;
			}
		}
	}
	cout << (d[S] > N ? -1 : d[S]) << endl;

}