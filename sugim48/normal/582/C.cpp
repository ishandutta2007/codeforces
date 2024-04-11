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

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<vector<int> > v(n + 1);
	for (int s = 1; s < n; s++)
		v[gcd(n, s)].push_back(s);
	ll ans = 0;
	for (int d = 1; d <= n; d++) {
		if (v[d].empty()) continue;
		vector<int> maxi(d);
		int hoge = 0;
		for (int i = 0; i < n; i++) {
			maxi[hoge] = max(maxi[hoge], a[i]);
			hoge++;
			if (hoge == d) hoge -= d;
		}
		vector<bool> b(n);
		int _i = -1;
		hoge = 0;
		for (int i = 0; i < n; i++) {
			b[i] = (a[i] == maxi[hoge]);
			if (!b[i]) _i = i;
			hoge++;
			if (hoge == d) hoge -= d;
		}
		if (_i == -1) {
			ans += (ll)n * v[d].size();
			continue;
		}
		int x = 0;
		vector<int> unko;
		hoge = (_i + 1) % n;
		for (int k = 1; k <= n; k++) {
			if (b[hoge]) x++;
			else {
				if (x) unko.push_back(x);
				x = 0;
			}
			hoge++;
			if (hoge == n) hoge -= n;
		}
		sort(unko.begin(), unko.end());
		int m = unko.size();
		vector<int> sum(m + 1);
		for (int j = m - 1; j >= 0; j--)
			sum[j] = sum[j + 1] + unko[j];
		for (int k = 0; k < v[d].size(); k++) {
			int s = v[d][k];
			int j = lower_bound(unko.begin(), unko.end(), s) - unko.begin();
			ans += sum[j] - (m - j) * (s - 1);
		}
	}
	cout << ans << endl;
}