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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, k; cin >> N >> k;
	vector<ll> v;
	ll x = 1;
	rep(t, 100) {
		v.pb(x);
		x *= k;
		if (abs(x) > 1e15) break;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	ll sum = 0;
	map<ll, int> mp;
	mp[sum]++;
	ll ans = 0;
	while (N--) {
		int a; scanf("%d", &a);
		sum += a;
		for (ll x: v) if (mp.count(sum - x)) ans += mp[sum - x];
		mp[sum]++;
	}
	cout << ans << endl;
}