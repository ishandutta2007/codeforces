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
double PI2 = M_PI * 2;

ll calc(vector<vector<int> >& a, int y, int x) {
	int N = a.size(), M = a[0].size();
	ll sum = 0;
	rep(i, N) rep(j, M) {
		ll dy = (i * 4 + 2) - y * 4, dx = (j * 4 + 2) - x * 4;
		sum += a[i][j] * (dy * dy + dx * dx);
	}
	return sum;
}

int f(vector<vector<int> > a) {
	int N = a.size(), M = a[0].size();
	int lb = -1, ub = N;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		ll z1 = calc(a, mid, 0), z2 = calc(a, mid + 1, 0);
		if (z1 <= z2) ub = mid;
		else lb = mid;
	}
	return ub;
}

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int> > a(N, vector<int>(M));
	vector<vector<int> > b(M, vector<int>(N));
	rep(i, N) rep(j, M) scanf("%d", &a[i][j]), b[j][i] = a[i][j];
	int y = f(a), x = f(b);
	cout << calc(a, y, x) << endl;
	cout << y << ' ' << x << endl;
}