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
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i], a[i]--;
	vector<int> ans(N);
	rep(l, N) {
		vector<int> num(N);
		int k0 = 0;
		for (int r = l; r < N; r++) {
			int k = a[r];
			num[k]++;
			if (i_i(num[k], -k) > i_i(num[k0], -k0)) k0 = k;
			ans[k0]++;
		}
	}
	rep(k, N) cout << ans[k] << ' ';
	cout << endl;
}