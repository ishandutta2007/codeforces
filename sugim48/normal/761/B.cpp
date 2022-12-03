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
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N, L; cin >> N >> L;
	vector<int> a(N), b(N);
	rep(i, N) cin >> a[i];
	rep(i, N) cin >> b[i];
	rep(x, L) rep(y, L) {
		vector<bool> v(L), w(L);
		rep(i, N) v[(x + a[i]) % L] = true;
		rep(i, N) w[(y + b[i]) % L] = true;
		if (v == w) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}