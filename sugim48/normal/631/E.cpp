#define _USE_MATH_DEFINES
#include <algorithm>
#include <complex>
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
#include <random>
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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef pair<ll, char> ll_c;
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll f(int N, vector<int>& a) {
	vector<ll> sum(N + 1);
	for (int i = 0; i < N; i++)
		sum[i + 1] = sum[i] + a[i];
	vector<i_ll> b;
	ll ma = 0;
	for (int i = 0; i < N; i++) {
		for (;;) {
			int n = b.size();
			if (n <= 1) break;
			int dx1 = b[n - 1].first - b[n - 2].first;
			ll dy1 = b[n - 1].second - b[n - 2].second;
			int dx2 = i - b[n - 1].first;
			ll dy2 = sum[i] - b[n - 1].second;
			if (dx1 * dy2 > dx2 * dy1) break;
			b.pop_back();
		}
		b.push_back(i_ll(i, sum[i]));
		int n = b.size();
		int lb = 0, ub = n - 1;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if ((ll)a[i] * (b[mid + 1].first - b[mid].first) >= b[mid + 1].second - b[mid].second)
				lb = mid;
			else
				ub = mid;
		}
		ma = max(ma, b[n - 1].second - b[lb].second - (ll)(b[n - 1].first - b[lb].first) * a[i]);
		if (lb + 1 < n)
			ma = max(ma, b[n - 1].second - b[lb + 1].second - (ll)(b[n - 1].first - b[lb + 1].first) * a[i]);
	}
	return ma;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	ll sum = 0;
	for (int i = 0; i < N; i++)
		sum += (ll)(i + 1) * a[i];
	ll ma = f(N, a);
	reverse(a.begin(), a.end());
	for (int i = 0; i < N; i++)
		a[i] *= -1;
	ma = max(ma, f(N, a));
	cout << sum + ma << endl;
}