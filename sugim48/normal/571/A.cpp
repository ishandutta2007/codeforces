#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
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
ll INF = LLONG_MAX / 10;

ll f(int a, int b, int c, int n) {
	if (a - b - c + n < 0) return 0;
	int x = (a - b - c + n) / 2;
	if (x > n) x = n;
	return (ll)(x + 2) * (x + 1) / 2;
}

int main() {
	int a, b, c, l;
	cin >> a >> b >> c >> l;
	ll sum = 0;
	for (int n = 0; n <= l; n++) {
		sum += (ll)(n + 2) * (n + 1) / 2;
		sum -= f(a, b, c, n);
		sum -= f(b, c, a, n);
		sum -= f(c, a, b, n);
	}
	cout << sum << endl;
}