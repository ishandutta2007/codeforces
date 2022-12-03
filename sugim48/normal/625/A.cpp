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
struct edge { int u, v; char c; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll solve(ll n, ll a, ll b, ll c) {
	ll d = b - c;
	if (a <= d || n < b) return n / a;
	n -= b;
	ll k = n / d;
	n -= k * d;
	n += c;
	return 1 + k + n / a;
}

int main() {
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << solve(n, a, b, c) << endl;
}