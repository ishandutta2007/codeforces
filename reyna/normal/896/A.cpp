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
const int N = (int) 1e5 + 5, mod = (int) 0, oo = 2e18;
int len[N];
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string x0 = "What are you doing while sending \"";
string x1 = "\"? Are you busy? Will you send \"";
string x2 = "\"?";
char f(int n, int k) {
	if (n == 0) {
		return f0[k];
	}
	if (k < (int) x0.size()) {
		return x0[k];	
	}
	k -= (int) x0.size();
	if (k < len[n - 1]) {
		return f(n - 1, k);	
	}
	k -= len[n - 1];
	if (k < (int) x1.size()) {
		return x1[k];
	}
	k -= (int) x1.size();
	if (k < len[n - 1]) {
		return f(n - 1, k);	
	}
	k -= len[n - 1];
	if (k >= (int) x2.size()) assert(0);
	return x2[k];
}
int32_t main() {
	len[0] = (int) f0.length();
	for (int j = 1; j < N; ++j)
		len[j] = min(oo, len[j - 1] * 2 + (int) x0.size() + (int) x1.size() + (int) x2.size());
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		--k;
		if (len[n] <= k) {
			cout << ".";
		} else {
			cout << f(n, k);	
		}
	}
}