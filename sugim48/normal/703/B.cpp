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

int main() {
	int N, K; cin >> N >> K;
	vector<ll> a(N);
	ll sum = 0;
	for (ll& x: a) {
		scanf("%d", &x);
		sum += x;
	}
	vector<bool> cap(N);
	ll unko = 0;
	while (K--) {
		int i; scanf("%d", &i); i--;
		cap[i] = true;
		unko += a[i];
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (cap[i]) ans += (ll)a[i] * (sum - a[i]);
		else {
			ll x = unko;
			if (!cap[(i + 1) % N]) x += a[(i + 1) % N];
			if (!cap[(i + N - 1) % N]) x += a[(i + N - 1) % N];
			ans += (ll)a[i] * x;
		}
	}
	cout << ans / 2 << endl;
}