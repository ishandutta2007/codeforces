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

ll f(int N, int K, int x, int y, vector<ll> a, vector<int> b) {
	vector<i_i> ai(N);
	rep(i, N) ai[i] = i_i(a[i], i);
	sort(ai.begin(), ai.end());
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	ll sum = 0, ans = LLONG_MAX;
	for (i_i p: ai) {
		int i = p.second;
		ll z = (ll)a[i] * x - (ll)b[i] * y;
		pq.push(z);
		sum += z;
		if (pq.size() > K) {
			sum -= pq.top();
			pq.pop();
		}
		if (pq.size() == K) ans = min(ans, (ll)K * a[i] * x - sum);
	}
	return ans;
}

int main() {
	int N, K, x, y;
	cin >> N >> K >> x >> y;
	x = min(x, y * 5);
	vector<ll> a(N);
	rep(i, N) scanf("%lld", &a[i]), a[i] += INT_MAX;
	ll ans = LLONG_MAX;
	rep(k, 5) {
		vector<ll> _a(N);
		vector<int> b(N);
		rep(i, N) {
			int t;
			for (t = 0; (a[i] + t) % 5 != k; t++);
			b[i] = t;
			_a[i] = (a[i] + b[i]) / 5;
		}
		ans = min(ans, f(N, K, x, y, _a, b));
	}
	cout << ans << endl;
}