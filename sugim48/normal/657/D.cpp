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

bool unko(i_i l, i_i r) {
	return (ll)l.first * r.second < (ll)r.first * l.second;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<int> A = a;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int M = A.size();
	vector<int> t(N);
	rep(i, N) scanf("%d", &t[i]);
	ll T = 0;
	rep(i, N) T += t[i];
	vector<i_i> at(N);
	rep(i, N) at[i] = i_i(a[i], t[i]);
	sort(at.rbegin(), at.rend(), unko);
	rep(i, N) a[i] = at[i].first, t[i] = at[i].second;
	vector<int> id(N);
	rep(i, N) id[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin();
	vector<ll> sum(N + 1);
	rep(i, N) sum[i + 1] = sum[i] + t[i];
	vector<int> l(N), r(N);
	for (int i = 0; i + 1 < N; i++) {
		l[i + 1] = l[i];
		if (unko(at[i + 1], at[i])) l[i + 1] = i + 1;
	}
	r[N - 1] = N;
	for (int i = N - 1; i - 1 >= 0; i--) {
		r[i - 1] = r[i];
		if (unko(at[i], at[i - 1])) r[i - 1] = i;
	}
	double lb = 0, ub = 1;
	rep(_t, 50) {
		double mid = (lb + ub) / 2;
		vector<double> mi(M, DBL_MAX), ma(M, -DBL_MIN);
		rep(i, N) {
			int j = id[i];
			double x = a[i] * (1 - mid * (sum[l[i]] + t[i]) / T);
			ma[j] = max(ma[j], x);
			x = a[i] * (1 - mid * sum[r[i]] / T);
			mi[j] = min(mi[j], x);
		}
		bool ok = true;
		rep(j, M - 1) if (ma[j] > mi[j + 1]) ok = false;
		if (ok) lb = mid;
		else ub = mid;
	}
	printf("%.15f\n", lb);
}