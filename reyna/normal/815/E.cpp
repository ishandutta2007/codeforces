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
const int N = (int) 505, mod = (int) 0;
set<int> values;
int contain[N][N];
int gd(int x) {
	return (x + 1) / 2;	
}
int32_t main() {
	int n, num;
	cin >> n >> num;
	if (num == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (num == 2) {
		cout << n << endl;
		return 0;
	}
	n -= 2;
	num -= 2;
	values.insert(n);
	for (int turn = 0; turn < 100; ++turn) {
		for (int x : values) if (x >= 1) {
			values.insert(gd(x) - 1);
			values.insert(x - gd(x));
		}
	}
	vector<int> all;
	for (int x : values) all.push_back(x);
	vector<int> dv;
	int sz = (int) all.size();
	sort(all.begin(), all.end());
	reverse(all.begin(), all.end());
	for (int x : all) dv.push_back(gd(x));
	sort(ALL(dv));
	dv.resize(unique(ALL(dv)) - dv.begin());
	reverse(dv.begin(), dv.end());
	int dsz = (int) dv.size();
	map<int, int> rev;
	for (int j = 0; j < dsz; ++j) rev[dv[j]] = j;
	map<int, int> pl;
	for (int j = 0; j < (int) all.size(); ++j) pl[all[j]] = j;
	for (int j = sz - 1; j >= 0; --j) {
		int x = all[j];
		contain[j][rev[gd(x)]] = 1;
		for (int k = 0; k < sz; ++k)
			contain[j][k] += contain[pl[gd(x) - 1]][k] + contain[pl[x - gd(x)]][k];
	}
	int house = 0, dist = -1;
	int tmp = num;
	for (int j = 0; j < dsz; ++j) {
		tmp -= contain[0][j];
		if (tmp <= 0) {
			dist = dv[j];
			tmp += contain[0][j];
			break;
		}
	}
//	cerr << " hi " << dist << ' ' << tmp << endl;
	if (dist == -1) assert(0);
	num = tmp - 1;
	int size = n;
	while (true) {
//		cerr << size << ' ' << house << ' ' << num << ' ' << dist << endl;
		if (gd(size) == dist) --num;
		if (num == -1 && gd(size) == dist) {
			cout << house + gd(size) + 1 << endl;
			return 0;
		}
		if (size == -1) break;
//		cerr << contain[pl[gd(size) - 1]][rev[dist]] << endl;
		if (num < contain[pl[gd(size) - 1]][rev[dist]]) {
//			cerr << " wtf " << endl;
			size = gd(size) - 1;
		} else {
			num -= contain[pl[gd(size) - 1]][rev[dist]];
//			cerr << " hello " << endl;
			house += gd(size);
			size = size - gd(size);
		}
	}
	
}