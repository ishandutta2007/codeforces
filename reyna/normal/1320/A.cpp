
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
const int N = (int) 1e6 + 6, M = 5e5 + 5, mod = (int) 0;
int a[N], cnt[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		cnt[a[j] - j + M] += a[j];
	}
	int res = 0;
	for (int j = 0; j < N; ++j) res = max(res, cnt[j]);
	cout << res << endl;
}