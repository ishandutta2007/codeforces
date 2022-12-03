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

int solve(int N, ll mov, ll rot, ll T, string& s) {
	if (s[0] == 'w') T -= rot;
	T--;
	if (T < 0) return 0;
	vector<ll> a(N), b(N);
	for (int i = 1; i <= N - 1; i++) {
		a[i] = a[i - 1];
		if (s[i] == 'w') a[i] += rot;
	}
	for (int i = 1; i <= N - 1; i++) {
		b[i] = b[i - 1];
		if (s[N - i] == 'w') b[i] += rot;
	}
	int lb = 0, ub = N;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		ll mi = LLONG_MAX;
		for (int i = 0; i <= mid; i++) {
			int j = mid - i;
			mi = min(mi, a[i] + b[j] + (i + j + min(i, j)) * mov);
		}
		if (mid + mi <= T) lb = mid;
		else ub = mid;
	}
	return lb + 1;
}

int main() {
	int N, mov, rot, T; cin >> N >> mov >> rot >> T;
	string s; cin >> s;
	cout << solve(N, mov, rot, T, s) << endl;
}