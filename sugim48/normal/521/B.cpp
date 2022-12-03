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
int INF = INT_MAX / 3;

int main() {
	int m; cin >> m;
	map<i_i, int> mp;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int> > _pq;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		mp[i_i(x[i], y[i])] = i;
		pq.push(i);
		_pq.push(i);
	}
	int ans = 0;
	for (int t = 0; t < m; t++) {
		int i;
		for (;;) {
			if (t % 2 == 0) {
				i = pq.top(); pq.pop();
			} else {
				i = _pq.top(); _pq.pop();
			}
			if (!mp.count(i_i(x[i], y[i])))
				continue;
			bool ok = true;
			for (int dx = -1; dx <= 1; dx++) {
				if (!mp.count(i_i(x[i] + dx, y[i] + 1)))
					continue;
				bool stable = false;
				for (int _dx = -1; _dx <= 1; _dx++)
					if (dx + _dx != 0 && mp.count(i_i(x[i] + dx + _dx, y[i])))
						stable = true;
				if (!stable) ok = false;
			}
			if (ok) break;
		}
		mp.erase(i_i(x[i], y[i]));
		for (int dx = -1; dx <= 1; dx++)
			if (mp.count(i_i(x[i] + dx, y[i] - 1))) {
				int _i = mp[i_i(x[i] + dx, y[i] - 1)];
				pq.push(_i);
				_pq.push(_i);
			}
		ans = ((ll)ans * m + i) % _MOD;
	}
	cout << ans << endl;
}