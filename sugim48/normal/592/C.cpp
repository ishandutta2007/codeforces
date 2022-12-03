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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	ll t, a, b; cin >> t >> a >> b;
	if (a > b) swap(a, b);
	t++;
	ll d = gcd(a, b), m;
	if ((double)a * b / d < 6000000000000000000LL) m = a / d * b;
	else m = 6000000000000000000LL;
	ll p = t / m * a + min(t % m, a) - 1;
	ll q = t - 1;
	ll _d = gcd(p, q);
	cout << p / _d << '/' << q / _d << endl;
}