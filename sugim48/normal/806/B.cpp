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

int f(int x, int y) {
	if (y * 2 > x) return 0;
	if (y * 4 > x) return 1;
	if (y * 8 > x) return 2;
	if (y * 16 > x) return 3;
	if (y * 32 > x) return 4;
	return 5;
}

int main() {
	int M = 5;
	int N; cin >> N;
	vector<vector<int> > a(N, vector<int>(M));
	rep(i, N) rep(j, M) cin >> a[i][j];
	vector<int> num(M);
	rep(i, N) rep(j, M) if (a[i][j] != -1) num[j]++;
	for (int n = 0; n <= 5000; n++) {
		vector<vector<bool> > pos(M, vector<bool>(6));
		for (int x = 0; x <= n; x++)
			rep(j, M)
				if (!x || a[0][j] != -1)
					pos[j][f(N + n, num[j] + x)] = true;
		int sum = 0;
		rep(j, M) {
			int ma = -INF;
			rep(k, 6) if (pos[j][k]) {
				int Vasya = (a[0][j] == -1 ? 0 : (k + 1) * (500 - a[0][j] * 2));
				int Petya = (a[1][j] == -1 ? 0 : (k + 1) * (500 - a[1][j] * 2));
				ma = max(ma, Vasya - Petya);
			}
			sum += ma;
		}
		if (sum > 0) {
			cout << n << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}