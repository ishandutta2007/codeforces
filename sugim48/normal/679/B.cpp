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

i_ll f(ll N) {
	if (!N) return i_ll(0, 0);
	int lb = 0, ub = 100001;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		if (mid * mid * mid <= N) lb = mid;
		else ub = mid;
	}
	ll n = lb;
	i_ll p1 = f(N - n * n * n);
	p1.first++; p1.second += n * n * n;
	if (n == 1) return p1;
	i_ll p2 = f(n * n * n - (n - 1) * (n - 1) * (n - 1) - 1);
	p2.first++; p2.second += (n - 1) * (n - 1) * (n - 1);
	return max(p1, p2);
}

int main() {
	ll N; cin >> N;
	i_ll p = f(N);
	cout << p.first << ' ' << p.second << endl;
}