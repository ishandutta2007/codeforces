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
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 2;

int main() {
	ll x, y, l, r;
	cin >> x >> y >> l >> r;
	set<ll> st;
	st.insert(l - 1);
	st.insert(r + 1);
	rep(a, 64) rep(b, 64) {
		double z = pow(x, a) + pow(y, b);
		if (z > r * 2) continue;
		ll X = 1, Y = 1;
		rep(t, a) X *= x;
		rep(t, b) Y *= y;
		ll Z = X + Y;
		if (l <= Z && Z <= r) st.insert(Z);
	}
	vector<ll> v(st.begin(), st.end());
	ll ma = 0;
	for (int i = 0; i + 1 < v.size(); i++)
		ma = max(ma, v[i + 1] - v[i] - 1);
	cout << ma << endl;
}