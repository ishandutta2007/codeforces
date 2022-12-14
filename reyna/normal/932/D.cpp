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
const int N = (int) 4e5 + 6, L = 20, mod = (int) 0;
int cnt, sumw[N][L], parw[N][L], up[N][L], mx[N][L], w[N];
int add_node(int p, int x) {
	up[cnt][0] = p;
	mx[cnt][0] = x;
	w[cnt] = x;
	if (p == -1) {
		parw[cnt][0] = -1;
		sumw[cnt][0] = x;
	} else {
		int v = p;
		for (int j = L - 1; j >= 0; --j) {
			if (up[v][j] != -1 && mx[v][j] < x) {
				v = up[v][j];	
			}
		}
		
		if (w[v] >= x) {
			parw[cnt][0] = v;	
			sumw[cnt][0] = x;
		} else {
			parw[cnt][0] = -1;
			sumw[cnt][0] = x;
		}
	}
	for (int j = 1; j < L; ++j) {
		if (up[cnt][j - 1] == -1) {
			up[cnt][j] = up[cnt][j - 1];
			mx[cnt][j] = mx[cnt][j - 1];
		} else {
			up[cnt][j] = up[up[cnt][j - 1]][j - 1];
			mx[cnt][j] = max(mx[cnt][j - 1], mx[up[cnt][j - 1]][j - 1]);
		}
		if (parw[cnt][j - 1] == -1) {
			parw[cnt][j] = parw[cnt][j - 1];
			sumw[cnt][j] = sumw[cnt][j - 1];
		} else {
			parw[cnt][j] = parw[parw[cnt][j - 1]][j - 1];
			sumw[cnt][j] = sumw[cnt][j - 1] + sumw[parw[cnt][j - 1]][j - 1];
		}
	}
	
	return cnt++;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	add_node(-1, 0);	
	int q, last = 0;
	cin >> q;
	while (q--) {
		int t, p, q;
		cin >> t >> p >> q;
		p ^= last;
		q ^= last;
		if (t == 1) {
			--p;
			add_node(p, q);
		} else {
			--p;
			int res = 0, cur = 0;
			for (int j = L - 1; j >= 0; --j) {
				if (parw[p][j] != -1 && sumw[p][j] + cur <= q) {
					res += 1 << j;
					cur += sumw[p][j];
					p = parw[p][j];
				}
			}
			if (cur + sumw[p][0] <= q) {
				++res;	
			}
			cout << res << '\n';
			last = res;
		}
	}
}