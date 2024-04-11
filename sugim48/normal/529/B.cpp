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

typedef pair<ll, i_i> P;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<int> w(n), h(n);
	for (int i = 0; i < n; i++)
		cin >> w[i] >> h[i];
	int mini = INT_MAX;
	for (int H = 1; H <= 1000; H++) {
		int W = 0, cnt = 0;
		bool ok = true;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			if (h[i] <= H) {
				W += w[i];
				if (w[i] <= H && h[i] < w[i])
					pq.push(w[i] - h[i]);
			}
			else {
				if (w[i] <= H) {
					W += h[i];
					cnt++;
				}
				else ok = false;
			}
		}
		if (!ok || cnt * 2 > n) continue;
		while (!pq.empty() && (cnt + 1) * 2 <= n) {
			W -= pq.top(); pq.pop();
			cnt++;
		}
		mini = min(mini, H * W);
	}
	cout << mini << endl;
}