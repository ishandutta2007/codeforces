#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;

ll cube_root(ll x) {
	ll lb = 0, ub = 1000001;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		if (mid * mid * mid <= x) lb = mid;
		else ub = mid;
	}
	return lb;
}

int unko[1000001];

bool solve(ll x, ll y) {
	ll z = x * y;
	ll z3 = cube_root(z);
	if (z3 * z3 * z3 != z) return false;
	set<ll> st;
	for (; z3 > 1; z3 /= unko[z3]) st.insert(unko[z3]);
	for (ll p: st) {
		int a = 0, b = 0;
		for (; x % p == 0; x /= p) a++;
		for (; y % p == 0; y /= p) b++;
		if ((a + b) % 3) return false;
		if (a > b * 2) return false;
		if (b > a * 2) return false;
	}
	if (x > 1 || y > 1) return false;
	return true;
}

int main() {
	for (int p = 2; p <= 1000000; p++)
		if (!unko[p])
			for (int q = p; q <= 1000000; q += p)
				unko[q] = p;
	int T; cin >> T;
	while (T--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%s\n", solve(x, y) ? "Yes" : "No");
	}
}