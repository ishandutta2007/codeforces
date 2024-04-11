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
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

int main() {
	int N, w; cin >> N >> w;
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	vector<int> b(N);
	int sum = 0;
	rep(i, N) {
		b[i] = (a[i] + 1) / 2;
		sum += b[i];
	}
	if (sum > w) {
		cout << -1 << endl;
		return 0;
	}
	vector<i_i> ai(N);
	rep(i, N) ai[i] = i_i(a[i], i);
	sort(ai.rbegin(), ai.rend());
	rep(t, N) {
		int i = ai[t].second;
		int d = min(a[i] - b[i], w - sum);
		b[i] += d;
		sum += d;
	}
	rep(i, N) cout << b[i] << ' ';
	cout << endl;
}