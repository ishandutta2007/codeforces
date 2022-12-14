
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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int parity = 0, mx = 0, sum = 0;
	for (int j = 0; j < n; ++j) {
		parity ^= a[j] & 1;
		mx = max(mx, a[j]);
		sum += a[j];
	}
	if (parity || mx + mx > sum) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}