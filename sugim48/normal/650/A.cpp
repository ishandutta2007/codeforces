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

int main() {
	int N; cin >> N;
	vector<int> x(N), y(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	map<int, int> X, Y;
	map<i_i, int> mp;
	for (int i = 0; i < N; i++) {
		X[x[i]]++;
		Y[y[i]]++;
		mp[i_i(x[i], y[i])]++;
	}
	ll ans = 0;
	for (auto it = X.begin(); it != X.end(); it++) {
		ll z = it->second;
		ans += z * (z - 1) / 2;
	}
	for (auto it = Y.begin(); it != Y.end(); it++) {
		ll z = it->second;
		ans += z * (z - 1) / 2;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ll z = it->second;
		ans -= z * (z - 1) / 2;
	}
	cout << ans << endl;
}