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
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int T1 = (n + k - 1) / k * t;
	int T2;
	for (T2 = 0; ; T2++) {
		if (T2 > 0 && T2 % t == 0) n -= k;
		if (T2 > d && (T2 - d) % t == 0) n -= k;
		if (n <= 0) break;
	}
	cout << (T1 > T2 ? "YES" : "NO") << endl;
}