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

const int N = (int) 0, mod = (int) 0;
#define int long long
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--) {
		long long p, q, b;
		cin >> p >> q >> b;
		if (p % q == 0) {
			cout << "Finite\n";	
		} else {
			p %= q;
			q = q / __gcd(p, q);
			int flag = 1;
			b = __gcd(q, b);
			while (q > 1 && flag) {
				int x = __gcd(q, b);
				if (x == 1) {
					flag = 0;
					cout << "Infinite\n";
					break;
				} else {
					q /= x;	
				}
			}
			if (flag) cout << "Finite\n";
		}
	}
}