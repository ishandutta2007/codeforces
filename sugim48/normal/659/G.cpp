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
	int N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		a[i]--;
	}
	ll x = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		ll h = a[i];
		if (i && a[i - 1] < a[i]) h = a[i - 1];
		ans = (ans + x * h) % MOD;
		if (i + 1 < N) x = x * min(h, a[i + 1]) % MOD;
		ans = (ans + a[i]) % MOD;
		x = (x + min(a[i], a[i + 1])) % MOD;
	}
	cout << ans << endl;
}