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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef pair<int, char> i_c;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int h, q; cin >> h >> q;
	if (q == 0) {
		if (h == 1) cout << 1 << endl;
		else cout << "Data not sufficient!" << endl;
		return 0;
	}
	ll l = (1LL << (h - 1)) - 1, r = (1LL << h) - 1;
	map<ll, int> m;
	for (int j = 0; j < q; j++) {
		int i, ans; ll L, R;
		scanf("%d%I64d%I64d%d", &i, &L, &R, &ans);
		L <<= (h - i); L--;
		R++; R <<= (h - i); R--;
		if (ans) {
			m[L]++; m[R]--;
		}
		else {
			m[l]++; m[L]--;
			m[R]++; m[r]--;
		}
	}
	int z = 0; ll ans, sum = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		ll x = it->first; int y = it->second;
		z += y;
		if (z == q) {
			ans = x + 1;
			it++; ll _x = it->first; it--;
			sum += _x - x;
		}
	}
	if (sum == 0) cout << "Game cheated!" << endl;
	if (sum == 1) cout << ans << endl;
	if (sum >= 2) cout << "Data not sufficient!" << endl;  
}