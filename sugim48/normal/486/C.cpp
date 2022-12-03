#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, p; string s; cin >> n >> p >> s;
	int l = INT_MAX, r = INT_MIN, ans = 0;
	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		int x = abs(s[i] - s[j]);
		if (x == 0) continue;
		l = min(l, i);
		r = max(r, i);
		ans += min(x, 26 - x);
	}
	if (ans == 0) {
		cout << 0 << endl;
		return 0;
	}
	p--;
	p = min(p, n - 1 - p);
	ans += r - l + min(abs(p - l), abs(p - r));
	cout << ans << endl;
}