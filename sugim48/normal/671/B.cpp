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

void solve(int N, vector<ll>& a, ll K) {
	ll lb = INT_MIN, ub = INT_MAX;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++)
			if (a[i] > mid)
				sum += a[i] - mid;
		if (sum <= K) ub = mid;
		else lb = mid;
	}
	ll x = ub;
	for (int i = 0; i < N; i++)
		if (a[i] > x) {
			K -= a[i] - x;
			a[i] = x;
		}
	for (int i = 0; i < N; i++)
		if (K && a[i] == x) a[i]--, K--;
}

int main() {
	int N; cin >> N;
	ll K; cin >> K;
	vector<ll> a(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &a[i]);
	sort(a.begin(), a.end());
	if (!K) {
		cout << a[N - 1] - a[0] << endl;
		return 0;
	}
	ll sum = 0;
	for (int i = 0; i < N; i++)
		sum += a[i];
	vector<ll> _a(N);
	for (int i = 0; i < N; i++)
		_a[i] = sum / N;
	sum %= N;
	for (int i = 0; i < N; i++) {
		if (sum > 0) _a[i]++, sum--;
		if (sum < 0) _a[i]--, sum++;
	}
	sort(_a.begin(), _a.end());
	ll need = 0;
	for (int i = 0; i < N; i++)
		need += abs(a[i] - _a[i]);
	need /= 2;
	if (need <= K) {
		cout << _a[N - 1] - _a[0] << endl;
		return 0;
	}
	solve(N, a, K);
	for (int i = 0; i < N; i++)
		a[i] *= -1;
	solve(N, a, K);
	sort(a.begin(), a.end());
	cout << a[N - 1] - a[0] << endl;
}