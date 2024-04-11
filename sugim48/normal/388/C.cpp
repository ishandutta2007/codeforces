#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	ll sum1 = 0, sum2 = 0;
	vector<int> v;
	while (N--) {
		int M; cin >> M;
		vector<int> a(M);
		rep(i, M) cin >> a[i];
		rep(i, M / 2) sum1 += a[i], sum2 += a[M - 1 - i];
		if (M % 2) v.pb(a[M / 2]);
	}
	sort(v.rbegin(), v.rend());
	rep(i, v.size()) 
		if (i % 2 == 0) sum1 += v[i];
		else sum2 += v[i];
	cout << sum1 << ' ' << sum2 << endl;
}