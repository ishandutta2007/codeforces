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

const int N = (int) 1e3 + 3, mod = (int) 0;
string best[N][2];
pair<int, int> par[N][2];
void show(int i, int j) {
	if (i == 0) {
		cout << 0 << ' ';
		return;
	}
	show(i - 1, par[i][j].first);
	cout << par[i][j].second << ' ';
}
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	best[0][0] = best[0][1] = s[0];
	memset(par, -1, sizeof par);
	for (int j = 1; j < n; ++j) {
		for (int pre = 0; pre <= 1; ++pre) {
			for (int flip = 0; flip <= 1; ++flip) {
				string cur = best[j - 1][pre];
				cur += s[j];
				if (flip) reverse(ALL(cur));
				if (best[j][0] == "" || best[j][0] > cur) {
					best[j][0] = cur;
					par[j][0] = mp(pre, flip);	
				}
				reverse(ALL(best[j][1]));
				reverse(ALL(cur));
				if (best[j][1] == "" || best[j][1] > cur) {
					best[j][1] = cur;
					par[j][1] = mp(pre, flip);
				}
				reverse(ALL(best[j][1]));
			}
		}
	}
	show(n - 1, 0);
}