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
	vector<vector<ll> > a(n, vector<ll>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = (s[j] == 'W' ? 1 : -1);
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			if (a[i][j] == 0) continue;
			cnt++;
			ll x = a[i][j];
			for (int _i = 0; _i <= i; _i++)
				for (int _j = 0; _j <= j; _j++)
					a[_i][_j] -= x;
		}
	cout << cnt << endl;
}