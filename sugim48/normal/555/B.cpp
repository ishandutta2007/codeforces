#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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

int main() {
	int n, m; cin >> n >> m;
	vector<ll> l(n), r(n);
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	vector<ll_i> e;
	for (int i = 0; i + 1 < n; i++)
		e.push_back(ll_i(l[i + 1] - r[i], ~i));
	vector<ll> a(m);
	for (int j = 0; j < m; j++) {
		cin >> a[j];
		e.push_back(ll_i(a[j], j));
	}
	sort(e.begin(), e.end());
	priority_queue<ll_i, vector<ll_i>, greater<ll_i> > pq;
	vector<int> ans(n - 1);
	for (int k = 0; k < e.size(); k++) {
		int j = e[k].second;
		if (j >= 0) {
			if (!pq.empty() && a[j] <= pq.top().first) {
				ans[pq.top().second] = j;
				pq.pop();
			}
		}
		else {
			int i = ~j;
			pq.push(ll_i(r[i + 1] - l[i], i));
		}
	}
	if (pq.empty()) {
		cout << "Yes" << endl;
		for (int i = 0; i + 1 < n; i++)
			cout << ans[i] + 1 << ' ';
		cout << endl;
	}
	else cout << "No" << endl;
}