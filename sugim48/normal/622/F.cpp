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
 
ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}
 
ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

int solve(int N, vector<int> A, int T) {
	if (T <= N) return A[T];
	ll l = 1;
	for (int i = 1; i <= N; i++)
		l = l * mod_inverse(-i, MOD) % MOD;
	ll unko = 1;
	for (int i = 0; i <= N; i++)
		unko = unko * (T - i) % MOD;
	ll sum = 0;
	for (int j = 0; j <= N; j++) {
		ll x = l * unko % MOD * mod_inverse(T - j, MOD) % MOD;
		sum = (sum + A[j] * x) % MOD;
		l = l * (j - N + MOD) % MOD;
		l = l * mod_inverse(j + 1, MOD) % MOD;
	}
	return (sum + MOD) % MOD;
}

int pow_mod(ll x, ll n, int m) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * x) % m;
		x = (x * x) % m;
	}
	return res;
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> A(k + 2);
	A[0] = 0;
	for (int i = 1; i < k + 2; i++)
		A[i] = (A[i - 1] + pow_mod(i, k, MOD)) % MOD;
	cout << solve(k + 1, A, n) << endl;
}