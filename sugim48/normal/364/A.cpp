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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

int inf = INT_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;

int main() {
	int a; cin >> a;
	string s; cin >> s;
	int n = s.length();
	vector<int> sum(n + 1);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + s[i] - '0';
	vector<int> v(40000);
	for (int l = 0; l <= n; l++)
		for (int r = l + 1; r <= n; r++)
			v[sum[r] - sum[l]]++;
	ll ans = 0;
	for (int l = 0; l <= n; l++)
		for (int r = l + 1; r <= n; r++) {
			int x = sum[r] - sum[l];
			if (x) { if (a % x == 0 && a / x < 40000) ans += v[a / x]; }
			else { if (!a) ans += n * (n + 1) / 2; }
		}
	cout << ans << endl;
}