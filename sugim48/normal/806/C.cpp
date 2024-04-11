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
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 2;

int main() {
	int N; cin >> N;
	vector<int> a(50), b(50);
	rep(t, N) {
		ll x; scanf("%lld", &x);
		int i;
		for (i = 0; (1LL<<(i + 1)) <= x; i++);
		if ((1LL<<i) == x) a[i]++;
		else b[i]++;
	}
	vector<int> ans;
	for (int n = 1; n <= a[0]; n++) {
		int prev = n, rest = n;
		bool ok = true;
		rep(i, 50) {
			int x = min(a[i], prev);
			rest = min(rest, x);
			int y = (a[i] - x) + b[i];
			if (y > rest) ok = false;
			rest -= y;
			prev = x;
		}
		if (ok) ans.pb(n);
	}
	if (ans.empty()) cout << -1 << endl;
	else {
		for (int n: ans) cout << n << ' ';
		cout << endl;
	}
}