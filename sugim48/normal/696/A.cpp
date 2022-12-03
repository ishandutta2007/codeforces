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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
typedef vector<vector<bool> > grid;

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll lca(ll u, ll v) {
	if (u == v) return u;
	return u > v ? lca(u / 2, v) : lca(u, v / 2);
}

ll f(ll u, vector<ll>& a, vector<ll>& b) {
	ll ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int k = 0;
		for (ll v = lca(u, a[i]); v > 1; v>>=1) k++;
		ans += k * b[i];
	}
	return ans;
}

int main() {
	vector<ll> a, b;
	int Q; cin >> Q;
	while (Q--) {
		int q; cin >> q;
		if (q == 1) {
			ll u, v, w; cin >> u >> v >> w;
			ll z = lca(u, v);
			a.push_back(z); b.push_back(-w * 2);
			a.push_back(u); b.push_back(w);
			a.push_back(v); b.push_back(w);
		}
		if (q == 2) {
			ll u, v; cin >> u >> v;
			ll z = lca(u, v);
			cout << f(u, a, b) + f(v, a, b) - f(z, a, b) * 2 << endl;
		}
	}
}