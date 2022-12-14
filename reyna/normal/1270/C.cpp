
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
	int tc;
	cin >> tc;
	while (tc--) {
	int n, sum = 0, xp = 0;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], sum += a[j], xp ^= a[j];
	sum += xp;
	cout << 2 << '\n';
	cout << xp << ' ' << sum << '\n';
	}
}