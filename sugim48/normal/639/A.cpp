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
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 2;

int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<i_i> v;
	while (Q--) {
		int t, i; scanf("%d%d", &t, &i); i--;
		if (t == 1) {
			v.pb(i_i(a[i], i));
			sort(v.rbegin(), v.rend());
			if (v.size() > K) v.pop_back();
		}
		if (t == 2) {
			bool ok = false;
			for (i_i p: v) if (p.second == i) ok = true;
			printf("%s\n", ok ? "YES" : "NO");
		}
	}
}