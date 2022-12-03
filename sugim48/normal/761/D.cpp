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
ll INF = LLONG_MAX / 10;
double EPS = 1e-10;

int main() {
	int N; ll l, r; cin >> N >> l >> r;
	vector<ll> a(N);
	rep(i, N) scanf("%lld", &a[i]), a[i] *= -1;
	vector<int> p(N);
	rep(i, N) scanf("%d", &p[i]), p[i]--;
	vector<int> pi(N);
	rep(i, N) pi[p[i]] = i;
	vector<ll> b(N);
	ll x = -INF;
	for (int i: pi) {
		b[i] = max(l, x - a[i] + 1);
		if (b[i] > r) {
			cout << -1 << endl;
			return 0;
		}
		x = a[i] + b[i];
	}
	rep(i, N) printf("%lld%c", b[i], i + 1 < N ? ' ' : '\n');
}