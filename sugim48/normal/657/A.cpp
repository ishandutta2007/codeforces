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

int main() {
	int N, d, h; cin >> N >> d >> h;
	if (h == 1) {
		if (N == 2 || d == 2)
			for (int u = 2; u <= N; u++)
				cout << 1 << ' ' << u << endl;
		else cout << -1 << endl;
		return 0;
	}
	if (d > h * 2) {
		cout << -1 << endl;
		return 0;
	}
	for (int u = 2; u <= h + 1; u++)
		cout << u - 1 << ' ' << u << endl;
	int prev = 1;
	for (int u = h + 2; u <= d + 1; u++) {
		cout << prev << ' ' << u << endl;
		prev = u;
	}
	for (int u = d + 2; u <= N; u++)
		cout << h << ' ' << u << endl;
}