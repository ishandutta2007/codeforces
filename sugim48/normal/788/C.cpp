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
struct edge { int v; ll w; };

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int main() {
	int x0, K; cin >> x0 >> K;
	vector<bool> a(2001);
	while (K--) {
		int x; scanf("%d", &x);
		a[1000 + x - x0] = true;
	}
	vector<int> d(4001, INF);
	d[2000 + 0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int dx = -1000; dx <= 1000; dx++) if (a[1000 + dx]) {
			int _x = x + dx;
			if (_x == 0) {
				cout << d[2000 + x] + 1 << endl;
				return 0;
			}
			if (-2000 <= _x && _x <= 2000 && d[2000 + _x] > d[2000 + x] + 1) {
				d[2000 + _x] = d[2000 + x] + 1;
				q.push(_x);
			}
		}
	}
	cout << -1 << endl;
}