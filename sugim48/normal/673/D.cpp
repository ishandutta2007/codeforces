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
	int N, M; cin >> N >> M;
	if (N == 4 || M < N + 1) {
		cout << -1 << endl;
		return 0;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a--; b--; c--; d--;
	vector<int> V;
	rep(u, N) if (u != a && u != b && u != c && u != d) V.pb(u);
	cout << a + 1 << ' ' << c + 1 << ' ';
	for (int u: V) cout << u + 1 << ' ';
	cout << d + 1 << ' ' << b + 1 << ' ';
	cout << endl;
	cout << c + 1 << ' ' << a + 1 << ' ';
	for (int u: V) cout << u + 1 << ' ';
	cout << b + 1 << ' ' << d + 1 << ' ';
	cout << endl;
}