#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
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

int main () {
	ll n; ll A; cin >> n >> A;
	vector<ll> d(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		scanf("%d", &d[i]);
		sum += d[i];
	}
	for (ll i = 0; i < n; i++) {
		ll lb = max(1LL, A - (sum - d[i]));
		ll ub = min(d[i], A - (n - 1));
		printf("%d ", d[i] - (ub - lb + 1));
	}
	cout << endl;
}