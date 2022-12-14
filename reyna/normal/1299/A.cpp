
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int cnt[32], a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		for (int b = 30; b >= 0; --b)
			if (a[j] >> b & 1)
				++cnt[b];
	}
	int res = 0, mxid = -1;
	for (int j = 0; j < n; ++j) {
		int x = a[j];
		int cur = 0;
		for (int b = 30; b >= 0; --b) {
			if (x >> b & 1) if (cnt[b] == 1) {
				cur |= 1 << b;
			}
		}
		if (cur >= res)
			mxid = j;
		res = max(res, cur);
	}
	cout << a[mxid] << ' ';
	for (int j = 0; j < n; ++j)
		if (mxid != j)
			cout << a[j] << ' ';
}