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

const int N = (int) 1e5 + 5, mod = (int) 0;
int o[N], a[N], b[N];
vector<int> res;
int cmp(int x, int y) { return b[x] > b[y]; }
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	for (int j = 0; j < n; ++j)
		cin >> b[j], o[j] = j;
	sort(o, o + n, cmp);
	set<pair<int, int>, greater<pair<int, int>>> best;
	best.insert(make_pair(a[o[0]], o[0]));
	int pt = 1;
	for (int j = 0; j < n / 2 + 1; ++j) {
		if ((int) best.size()) {
			auto x = *(best.begin());
			best.erase(x);
			res.push_back(x.second);
		}
		if (pt != n) best.insert(make_pair(a[o[pt]], o[pt])), ++pt;
		if (pt != n) best.insert(make_pair(a[o[pt]], o[pt])), ++pt;
	}
	cout << (int) res.size() << endl;
	for (int x : res) cout << x + 1 << ' ';
}