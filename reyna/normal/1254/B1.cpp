
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
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int sum = 0;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		sum += a[j];
	}
	if (sum == 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> pr;
	int tmp = sum;
	for (int d = 2; d * d <= sum; ++d) {
		if (tmp % d == 0) pr.pb(d);
		while (tmp % d == 0) {
			tmp /= d;
		}
	}
	if (tmp != 1) pr.pb(tmp);
	int res = 1e18;
	for (int p : pr) {
		int cur_sum = 0, cur_cost = 0;
		for (int j = 0; j < n; ++j) {
			cur_sum += a[j];
			cur_cost += min(cur_sum % p, p - (cur_sum % p));
		}
		res = min(res, cur_cost);
	}
	cout << res << endl;
	
	
}