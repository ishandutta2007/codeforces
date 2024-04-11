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
const int N = (int) 3e5 + 5, mod = (int) 0;
int res[N], px[N], py[N], o[N];
int cmp(int x, int y) { return px[x] - py[x] < px[y] - py[y]; }
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) o[j] = j, cin >> px[j] >> py[j];
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		int val = min(px[u] + py[v], py[u] + px[v]);
		res[u] -= val;
		res[v] -= val;
	}
	int sumx = 0;
	sort(o, o + n, cmp);
	for (int i = 0; i < n; ++i) {
		int j = o[i];
		res[j] += sumx;
		res[j] += i * py[j];
		res[j] += (n - 1 - i) * px[j];
		sumx += px[j];
	}
	int sumy = 0;
	for (int i = n - 1; i >= 0; --i) {
		int j = o[i];
		res[j] += sumy;
		sumy += py[j];
	}
	for (int j = 0; j < n; ++j) cout << res[j] << ' ';	
}