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

int main() {
	int p0x, p0y, p1x, p1y, p2x, p2y, p3x, p3y;
	int q0x, q0y, q1x, q1y, q2x, q2y, q3x, q3y;
	cin >> p0x >> p0y >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	cin >> q0x >> q0y >> q1x >> q1y >> q2x >> q2y >> q3x >> q3y;
	int pmx = (p0x + p1x + p2x + p3x) / 2;
	int pmy = (p0y + p1y + p2y + p3y) / 2;
	int len0 = abs(p0x * 2 - pmx);
	int qmx = (q0x + q1x + q2x + q3x) / 2;
	int qmy = (q0y + q1y + q2y + q3y) / 2;
	int len1 = abs(q0x * 2 + q0y * 2 - qmx - qmy);
	for (int i = pmx - len0; i <= pmx + len0; ++i)
		for (int j = pmy - len0; j <= pmy + len0; ++j)
			for (int x = qmx - len1; x <= qmx + len1; ++x)
				for (int y = qmy - len1; y <= qmy + len1; ++y)
					if (abs(qmx - x) + abs(y - qmy) <= len1) {
						if (i == x && j == y) {
							cout << "YES\n";
							return 0;
						}
					}
	cout << "NO\n";
}