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

const int N = (int) 105, mod = (int) 0;
int cnt[N];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (char c : s) cnt[c - '0']++;
	for (int res = N; res >= 0; --res) {
		if (cnt[8] < res) {
			continue;
		}
		int rest = cnt[8] - res;
		for (int j = 0; j < N; ++j)
			if (j != 8)
				rest += cnt[j];
		if ((rest / 10) >= res) {
			cout << res << endl;
			return 0;
		}
	}
}