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

int main() {
	int n, m; cin >> n >> m;
	vector<i_i> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	sort(p.begin(), p.end());
	vector<int> x(n), index(n), rev(n);
	for (int i = 0; i < n; i++) {
		x[i] = p[i].first;
		index[i] = p[i].second;
		rev[p[i].second] = i;
	}
	while (m--) {
		int a, l; scanf("%d%d", &a, &l);
		int i = rev[a - 1], dir = 0;
		vector<int> prev(2, -1);
		for (;;) {
			if (prev[dir] == i) {
				int j = prev[1 - dir];
				if (i == j) {
					printf("%d\n", index[i] + 1);
					break;
				}
				int dx = abs(x[j] - x[i]);
				l %= (ll)dx * 2;
			}
			prev[dir] = i;
			int j;
			if (dir == 0) 
				j = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1;
			else
				j = lower_bound(x.begin(), x.end(), x[i] - l) - x.begin();
			l -= abs(x[j] - x[i]);
			i = j;
			dir = 1 - dir;
		}
	}
}