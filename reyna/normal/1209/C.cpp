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

const int N = (int) 2e5 + 5, mod = (int) 0;
int res[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int found = 0;
		for (int d = -1; d <= 9; ++d) {
			int flag = 1;
			int cur_0 = 0, cur_1 = 0;
			for (int j = 0; j < n; ++j) {
				int x = (s[j] - '0');
				if (x == d + 1) {
					if (cur_1 > x) {
						if (cur_0 > x) { flag = 0; break; }
						cur_0 = x;
						res[j] = 1;
					} else {
						cur_1 = x;
						res[j] = 2;
					}
				} else if (x <= d) {
					if (cur_0 > x) { flag = 0; break; }
					res[j] = 1;
					cur_0 = x;
				} else {
					if (cur_1 > x) { flag = 0; break; }
					res[j] = 2;
					cur_1 = x;
				}
			}
			if (flag) {
				found = 1;
				for (int j = 0; j < n; ++j) {
					cout << res[j];
				}
				cout << '\n';
				break;
			}
		}
		if (!found) {
			cout << '-' << '\n';	
		}
	}
}