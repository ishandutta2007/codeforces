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

const int N = (int) 2005, mod = (int) 0;
int n, who[N], nxt[N], ops[N * 4], ed;
void do_op(int k) {
	if (k == 0) return;
	ops[ed++] = k;
	int pt = 0;
	for (int j = n - 1; j >= n - k; --j) {
		nxt[pt++] = who[j];	
	}
	for (int j = 0; j < n - k; ++j) nxt[pt++] = who[j];
	for (int j = 0; j < n; ++j) who[j] = nxt[j];
}
void get_done(int ind, int len) {
	do_op(n - len);	
	int pos = -1;
	for (int j = 0; j < n; ++j) if (ind == who[j]) pos = j;
	assert(pos != -1);
	do_op(n - pos - 1);
	do_op(1);
}
int main() {
	memset(who, -1, sizeof who);
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) if (s[i] == t[j] && who[i] == -1) {
			who[i] = j;
			break;
		}
	}
	for (int j = 0; j < n; ++j) if (who[j] == -1) {
		cout << -1 << endl;
		return 0;
	}
	int pl = 0, pr = 1;
	for (int j = 0; j < n; ++j) {
		if (~j & 1) {
			--pl;
		} else {
			++pr;
		}
	}
	int l = -pl - 1, r = l + 1;
	for (int j = 0; j < n; ++j) {
		if (~j & 1) {
			get_done(l, j);
			l = (l + n - 1) % n;
		} else {
			get_done(r, j);
			r = (r + n + 1) % n;
		}
	}
	for (int j = 0; j < n; ++j) if (who[j] != j) {
		do_op(n);	
		break;
	}
	for (int j = 0; j < n; ++j) if (who[j] != j) assert(0);
	cout << ed << endl;
	for (int j = 0; j < ed; ++j) cout << ops[j] << ' ';
	
	
	
}