
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
int a[N], b[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n - 1; ++j) b[j] = a[j + 1] - a[j];
	sort(b, b + n - 1);
	reverse(b, b + n - 1);
	int res = a[n - 1] - a[0];
	for (int j = 0; j < k - 1; ++j)
		res -= b[j];
	cout << res << endl;
}