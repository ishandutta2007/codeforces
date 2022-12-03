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
	int n, m; cin >> n >> m;
	vector<i_i> E, F;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		if (b) E.push_back(i_i(a, i));
		else F.push_back(i_i(a, i));
	}
	E.push_back(i_i(INT_MAX, 0));
	sort(E.begin(), E.end());
	sort(F.begin(), F.end());
	vector<int> u(m), v(m);
	int f = 0, x = 0, y = 2;
	for (int e = 0; e < n; e++) {
		ll unko = (ll)e * (e - 1) / 2;
		for (; f < F.size() && F[f].first < E[e].first; f++) {
			if (f >= unko) {
				cout << -1 << endl;
				return 0;
			}
			int i = F[f].second;
			u[i] = x;
			v[i] = y;
			x++;
			if (x + 1 == y) {
				y++;
				x = 0;
			}
		}
		if (e == n - 1) break;
		int i = E[e].second;
		u[i] = e;
		v[i] = e + 1;
	}
	for (int i = 0; i < m; i++)
		printf("%d %d\n", u[i] + 1, v[i] + 1);
}