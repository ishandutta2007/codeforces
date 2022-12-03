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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll f(int N, vector<int>& a, string& s) {
	vector<ll> sum(N + 1);
	for (int i = N - 1; i >= 0; i--) {
		sum[i] = sum[i + 1];
		if (s[i] == 'B') sum[i] += a[i];
	}
	ll x = 0, ma = sum[0];
	for (int i = 0; i < N; i++) {
		if (s[i] == 'A') x += a[i];
		ma = max(ma, sum[i + 1] + x);
	}
	return ma;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	string s; cin >> s;
	ll ans = f(N, a, s);
	reverse(a.begin(), a.end());
	reverse(s.begin(), s.end());
	ans = max(ans, f(N, a, s));
	cout << ans << endl;
}