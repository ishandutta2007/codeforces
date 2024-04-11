#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i], a[i]--;
	vector<int> cycle(N);
	rep(i, N) {
		int T;
		for (T = 1; T <= 200; T++) {
			int j = i;
			rep(t, T) j = a[j];
			if (j == i) break;
		}
		cycle[i] = T;
	}
	ll m = 1;
	int ma = 1;
	rep(i, N) {
		if (cycle[i] <= 200) {
			m = lcm(m, cycle[i]);
			continue;
		}
		int T;
		for (T = 1; ; T++) {
			int j = i;
			rep(t, T) j = a[j];
			if (cycle[j] <= 200) break;
		}
		ma = max(ma, T);
	}
	ll ans;
	for (ans = 0; ans < ma; ans += m);
	cout << ans << endl;
}