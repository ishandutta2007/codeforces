#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
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
	ll n, r, avg; cin >> n >> r >> avg;
	ll line = n * avg, suma = 0;
	vector<ll_ll> p(n);
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		suma += a;
		p[i] = ll_ll(b, a);
	}
	sort(p.begin(), p.end());
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = p[i].second;
		b[i] = p[i].first;
	}
	ll sumb = 0;
	for (int i = 0; i < n; i++) {
		if (suma >= line) break;
		ll x = min(r - a[i], line - suma);
		suma += x;
		sumb += x * b[i];
	}
	cout << sumb << endl;
}