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

const int N = (int) 1e6 + 5, mod = (int) 0;
string fst = "sjfnb", scd = "cslnb";
int a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	sort(a, a + n);
	int cnt = 0;
	for (int j = 1; j < n; ++j) {
		cnt += (a[j] == a[j - 1]);
	}
	int cnt0 = 0;
	for (int j = 0; j < n; ++j) {
		cnt0 += (a[j] == 0);
	}
	if (cnt0 > 1) {
		cout << scd << endl;
		return 0;
	}
	if (cnt > 1) {
		cout << scd << endl;
		return 0;
	}
	if (cnt == 1) {
		for (int j = 1; j < n; ++j)
			if (a[j] == a[j - 1]) {
				--a[j - 1];
			}
		sort(a, a + n);
		cnt = 0;
		for (int j = 0; j < n - 1; ++j) {
			if (a[j] == a[j + 1]) {
				cout << scd << endl;
				return 0;
			}
		}
		swap(fst, scd);
	}
	int parity = 0;
	for (int j = 0; j < n; ++j) {
		int use = a[j] - j;	
		parity ^= use & 1;
	}
	cout << (parity == 0 ? scd : fst) << endl;
	
}