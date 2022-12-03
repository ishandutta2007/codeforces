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
ll INF = LLONG_MAX / 10;

int main() {
	int N; ll k; cin >> N >> k;
	N++;
	vector<ll> a(N);
	rep(i, N) scanf("%lld", &a[i]);
	vector<ll> pre(N + 1);
	int r = N;
	for (int i = 1; i <= N; i++) {
		ll x = pre[i - 1] + a[i - 1];
		if (x % 2) {
			r = i;
			break;
		}
		pre[i] = x / 2;
	}
	vector<ll> suf(N + 1);
	for (int i = N - 1; i >= 0; i--) {
		ll x = suf[i + 1] + a[i];
		suf[i] = max(-INF, min(INF, x * 2));
	}
	int ans = 0;
	rep(i, r) {
		ll x = pre[i] + suf[i + 1];
		if (abs(x) <= k && !(i == N - 1 && !x)) ans++;
	}
	cout << ans << endl;
}