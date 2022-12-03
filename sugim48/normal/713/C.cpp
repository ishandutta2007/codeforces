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

ll INF = LLONG_MAX / 10;

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	vector<vector<ll_ll> > v(N + 1);
	vector<vector<ll> > unko(N + 1);
	v[0].push_back(ll_ll(-INF, 0));
	unko[0].push_back(0);
	for (int i = 1; i <= N; i++) {
		ll A = a[i - 1];
		v[i] = v[i - 1];
		for (ll_ll& z: v[i]) {
			z.first++;
			z.second += abs(A - z.first);
		}
		ll x = A, sum = 0, mi = INF;
		for (int j = i - 1; j >= 0; j--) {
			sum += abs(a[j] - x);
			int k = lower_bound(v[j].begin(), v[j].end(), ll_ll(x, LLONG_MIN)) - v[j].begin() - 1;
			if (k >= 0) mi = min(mi, sum + unko[j][k]);
			x--;
		}
		v[i].push_back(ll_ll(A, mi));
		sort(v[i].begin(), v[i].end());
		unko[i] = vector<ll>(v[i].size());
		ll mya = INF;
		for (int k = 0; k < v[i].size(); k++) {
			if (v[i][k].second > INF * 2) v[i][k].second = INF * 2;
			mya = min(mya, v[i][k].second);
			unko[i][k] = mya;
		}
	}
	cout << unko.back().back() << endl;
}