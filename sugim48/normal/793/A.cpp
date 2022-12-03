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

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int main() {
	int N, d; cin >> N >> d;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	int mi = INF;
	rep(i, N) mi = min(mi, a[i]);
	rep(i, N) if ((a[i] - mi) % d) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	rep(i, N) ans += (a[i] - mi) / d;
	cout << ans << endl;
}