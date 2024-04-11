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
#include <unordered_map>
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
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

int main() {
	vector<ll> a;
	for (int x = 1; x <= 9; x++) {
		ll y = x;
		rep(t, 12) a.pb(y), y *= 10;
	}
	sort(a.begin(), a.end());
	ll x; cin >> x;
	ll y = *upper_bound(a.begin(), a.end(), x);
	cout << y - x << endl;
}