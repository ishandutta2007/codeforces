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
#include <list>
#include <numeric>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define pb push_back
 
int INF = INT_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N; N--;
	ll a0, b0; cin >> a0 >> b0;
	vector<ll> a(N), b(N);
	for (int i = 0; i < N; i++)
		scanf("%lld%lld", &a[i], &b[i]);
	vector<ll_ll> ab(N);
	for (int i = 0; i < N; i++)
		ab[i] = ll_ll(a[i], b[i]);
	sort(ab.rbegin(), ab.rend());
	for (int i = 0; i < N; i++)
		a[i] = ab[i].first, b[i] = ab[i].second;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	int i = 0, ans = INT_MAX;
	for (;;) {
		for (; i < N && a[i] > a0; i++) pq.push(b[i] - a[i] + 1);
		ans = min(ans, (int)pq.size());
		if (pq.empty()) break;
		ll x = pq.top();
		if (x > a0) break;
		a0 -= x;
		pq.pop();
	}
	cout << ans + 1 << endl;
}