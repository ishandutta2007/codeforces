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

typedef pair<ll, i_i> P;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			m[j * a[i]] = j;
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		int ans = k + 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= k; j++) {
				int y = x - j * a[i];
				if (m.count(y)) ans = min(ans, j + m[y]);
			}
		if (ans == k + 1) ans = -1;
		cout << ans << endl;
	}
}