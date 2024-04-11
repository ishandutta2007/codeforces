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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N, K; cin >> N >> K;
	vector<int> l(N), r(N);
	rep(i, N) scanf("%d%d", &l[i], &r[i]), r[i]++;
	vector<i_i> lr(N);
	rep(i, N) lr[i] = i_i(l[i], r[i]);
	sort(lr.begin(), lr.end());
	priority_queue<int, vector<int>, greater<int> > pq;
	int ma = 0, l0, r0;
	rep(i, N) {
		int l = lr[i].first, r = lr[i].second;
		pq.push(r);
		if (pq.size() > K) pq.pop();
		if (pq.size() == K) {
			int R = pq.top();
			if (R - l > ma) {
				ma = R - l;
				l0 = l;
				r0 = R;
			}
		}
	}
	cout << ma << endl;
	if (ma) {
		vector<int> v;
		rep(i, N) if (v.size() < K && l[i] <= l0 && r0 <= r[i]) v.pb(i);
		for (int i: v) printf("%d ", i + 1);
		cout << endl;
	}
	else {
		rep(i, K) printf("%d ", i + 1);
		cout << endl;
	}
}