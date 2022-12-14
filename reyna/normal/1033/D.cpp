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
const int N = (int) 505, M = 1500000, mod = (int) 998244353;
int changed[N], a[N], ispr[M];
vector<int> primes;
int32_t main() {
	map<int, int> pr;
	map<int, int> mark, cnt;
	set<int> st;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
	}
	for (int j = 2; j < M; ++j) ispr[j] = 1;
	for (int j = 2; j < M; ++j)
		if (ispr[j]) {
			primes.pb(j);
			for (int i = j + j; i < M; i += j)
				ispr[i] = 0;
		}
	for (int j = 0; j < n; ++j) {
		int &x = a[j];
		int p = sqrt(x);
		for (int i = p - 100; i <= p + 100; ++i)
			if (i * i == x) {
				st.insert(i);		
			}
		for (int i : primes) {
			if (i > x) {
				if (x != 1) {
					st.insert(x);
					cnt[x]++;
					changed[j] = 1;
					x = 1;
				}
				break;
			}
			if (x % i == 0) {
				st.insert(i);
				changed[j] = 1;
				while (x % i == 0) x /= i, cnt[i]++;
			}
		}
		if (changed[j] && x != 1) {
			st.insert(x);
			cnt[x]++;
			x = 1;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i] != a[j]) {
				int g = __gcd(a[i], a[j]);
				if (g != 1 && g != a[i]) {
					st.insert(g);
					st.insert(a[i] / g);
					st.insert(a[j] / g);
				}
			}
	for (int r = 0; r < 4; ++r) for (int j = 0; j < n; ++j) {
		for (int x : st) while (a[j] % x == 0) changed[j] = 1, cnt[x]++, a[j] /= x;
		if (changed[j] && a[j] != 1) st.insert(a[j]);
	}
	for (int j = 0; j < n; ++j) {
		if (a[j] != 1) {
			if (!changed[j])
				mark[a[j]] = 1;
			cnt[a[j]]++;
		}
	}
	int res = 1;
	for (auto x : cnt) {
		int num = x.first, seen = x.second;
		res = res * (LL) (seen + 1) % mod;
		if (mark[num]) {
			res = res * (LL) (seen + 1) % mod;
		}
	}
	cout << res << endl;
	
}