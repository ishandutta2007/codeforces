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

ll INF = LLONG_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void f(int x, set<int>& st) {
	for (int p = 2; p * p <= x; p++)
		if (x % p == 0) {
			st.insert(p);
			for (; x % p == 0; x /= p);
		}
	if (x > 1) st.insert(x);
}

int main() {
	int N; ll x, y; cin >> N >> x >> y;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}
	set<int> st;
	f(a[0], st);
	f(a[0] + 1, st);
	f(a[0] - 1, st);
	f(a[N - 1], st);
	f(a[N - 1] + 1, st);
	f(a[N - 1] - 1, st);
	ll ans = INF;
	for (int p: st) {
		vector<ll> r(N + 1);
		for (int i = N - 1; i >= 0; i--) {
			r[i] = r[i + 1] - x;
			if (a[i] % p == 0);
			else if ((a[i] + 1) % p == 0 || (a[i] - 1) % p == 0) r[i] += y;
			else r[i] = INF;
		}
		for (int i = N - 1; i >= 0; i--)
			r[i] = min(r[i], r[i + 1]);
		vector<ll> l(N + 1);
		for (int i = 1; i <= N; i++) {
			l[i] = l[i - 1] - x;
			if (a[i - 1] % p == 0);
			else if ((a[i - 1] + 1) % p == 0 || (a[i - 1] - 1) % p == 0) l[i] += y;
			else l[i] = INF;
		}
		for (int i = 0; i <= N; i++)
			ans = min(ans, l[i] + r[i]);
	}
	cout << ans + N * x << endl;
}