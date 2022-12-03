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
#include <cassert>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef vector<int> vi;
struct edge { int v; ll w; };
 
const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	cout << "YES" << endl;
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	int d = 0;
	rep(i, N) d = gcd(d, a[i]);
	if (d > 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> v;
	if (a[0] % 2) v.pb(0);
	rep(i, N - 1) if (a[i] % 2 != a[i + 1] % 2) v.pb(i + 1);
	if (a[N - 1] % 2) v.pb(N);
	int ans = 0;
	for (int k = 0; k * 2 < v.size(); k++) {
		int d = v[k * 2 + 1] - v[k * 2];
		ans += d / 2 + (d % 2) * 2;
	}
	cout << ans << endl;
}