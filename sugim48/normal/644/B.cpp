#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <complex>
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
struct edge { int v; ll w; };

int MOD = 1000000007;

int main() {
	int N, b; cin >> N >> b;
	vector<ll> t(N), d(N);
	for (int i = 0; i < N; i++)
		scanf("%lld%lld", &t[i], &d[i]);
	t.push_back(LLONG_MAX);
	queue<int> q;
	ll T = 0;
	vector<ll> ans(N, -1);
	for (int i = 0; i <= N; i++) {
		while (T <= t[i] && !q.empty()) {
			int j = q.front(); q.pop();
			T += d[j];
			ans[j] = T;
		}
		if (q.size() == b) continue;
		q.push(i);
		T = max(T, t[i]);
	}
	for (int i = 0; i < N; i++)
		printf("%lld ", ans[i]);
	cout << endl;
}