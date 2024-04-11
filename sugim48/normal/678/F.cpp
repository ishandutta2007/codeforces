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
int INF = INT_MAX / 2;

int B = 1000;

bool f(i_i& p, i_i& q, i_i& r) {
	ll dx1 = q.first - p.first, dy1 = q.second - p.second;
	ll dx2 = r.first - q.first, dy2 = r.second - q.second;
	return dx2 * dy1 <= dx1 * dy2;
}

int main() {
	int Q; cin >> Q;
	vector<int> t(Q), a(Q), b(Q);
	for (int k = 0; k < Q; k++) {
		scanf("%d", &t[k]);
		if (t[k] == 1) scanf("%d%d", &a[k], &b[k]);
		if (t[k] == 2) {
			scanf("%d", &a[k]);
			a[k]--;
		}
		if (t[k] == 3) scanf("%d", &a[k]);
	}
	vector<int> X;
	for (int k = 0; k < Q; k++)
		if (t[k] == 1)
			X.push_back(a[k]);
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	int M = X.size();
	vector<int> index(Q);
	for (int k = 0; k < Q; k++)
		if (t[k] == 1)
			index[k] = lower_bound(X.begin(), X.end(), a[k]) - X.begin();
	vector<bool> rem(Q), yotei(Q);
	for (int l = 0; l < Q; l += B) {
		int r = min(Q, l + B);
		for (int k = l; k < r; k++)
			if (t[k] == 2)
				yotei[a[k]] = true;
		vector<int> backet(M, -INF), added;
		for (int k = 0; k < l; k++) {
			if (t[k] != 1) continue;
			if (yotei[k]) {
				if (!rem[k]) added.push_back(k);
			}
			else {
				int i = index[k];
				backet[i] = max(backet[i], b[k]);
			}
		}
		int N = 0;
		vector<i_i> s;
		for (int i = 0; i < M; i++) {
			if (backet[i] == -INF) continue;
			i_i p(X[i], backet[i]);
			while (N >= 2 && f(s[N - 2], s[N - 1], p)) {
				N--;
				s.pop_back();
			}
			N++;
			s.push_back(p);
		}
		for (int k = l; k < r; k++) {
			if (t[k] == 1) added.push_back(k);
			if (t[k] == 2) rem[a[k]] = true;
			if (t[k] == 3) {
				ll z = a[k], ans = LLONG_MIN;
				int lb = 0, ub = N - 1;
				while (ub - lb > 1) {
					int mid = (lb + ub) / 2;
					if (s[mid].first * z + s[mid].second < s[mid + 1].first * z + s[mid + 1].second)
						lb = mid;
					else ub = mid;
				}
				if (lb < N) ans = max(ans, s[lb].first * z + s[lb].second);
				if (lb + 1 < N) ans = max(ans, s[lb + 1].first * z + s[lb + 1].second);
				for (int k: added)
					if (!rem[k])
						ans = max(ans, a[k] * z + b[k]);
				if (ans == LLONG_MIN) printf("EMPTY SET\n");
				else printf("%lld\n", ans);
			}
		}
	}
}