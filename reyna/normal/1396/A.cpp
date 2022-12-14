
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
int a[N], dp[N];
int n;
int solve(int rem) {
	if (dp[rem] != -1) return dp[rem];
	return dp[rem] = solve((rem + n-1) % n) + 1;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	if (n == 1) {
		cout << 1 << ' ' << 1 << ' ' << endl <<  -a[0] << endl;
		cout << 1 << ' ' << 1 << ' ' << endl <<  0 << endl;
		cout << 1 << ' ' << 1 << ' ' <<  endl << 0 << endl;
		return 0;
	}
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	cout << 1 << ' ' << n-1 << endl;
	for (int i = 0; i < n-1; ++i) {
		int rem = (a[i] % n + n) % n;
		int need = solve(rem);
		a[i] += need * (n-1);
		cout << need * (n-1) << ' ';
	}
	cout << endl;
	cout << 1 << ' ' << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << (i == n - 1 ? 0 : -a[i]) << ' ';	
	}
	cout << endl;
	cout << n << ' ' << n << endl;
	cout << -a[n-1] << endl;
}