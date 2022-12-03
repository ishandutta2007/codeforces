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

#define rep(i, N) for (int i = 0; i < N; i++)

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<vector<ll> > a(N, vector<ll>(3));
	rep(i, N) scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
	map<ll, vector<int> > mp;
	rep(i, N) {
		vector<ll> b = a[i];
		sort(b.begin(), b.end());
		mp[b[0] * MOD + b[1]].push_back(i);
		mp[b[0] * MOD + b[2]].push_back(i);
		mp[b[1] * MOD + b[2]].push_back(i);
	}
	ll ma = 0, i1, i2;
	for (auto z: mp) {
		ll h = z.first / MOD, w = z.first % MOD;
		vector<int> v = z.second;
		v.erase(unique(v.begin(), v.end()), v.end());
		vector<ll_i> d;
		for (int i: v) d.push_back(ll_i(a[i][0] + a[i][1] + a[i][2] - h - w, i));
		sort(d.rbegin(), d.rend());
		if (d.size() == 1) {
			ll x = min(min(h, w), d[0].first);
			if (x > ma) {
				ma = x;
				i1 = d[0].second;
				i2 = -1;
			}
		}
		else {
			ll x = min(min(h, w), d[0].first + d[1].first);
			if (x > ma) {
				ma = x;
				i1 = d[0].second;
				i2 = d[1].second;
			}
		}
	}
	if (i2 == -1) {
		cout << 1 << endl;
		cout << i1 + 1 << endl;
	}
	else {
		cout << 2 << endl;
		cout << i1 + 1 << ' ' << i2 + 1 << endl;
	}
}