#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll n, k;

bool check(ll a, ll b, ll c) {
	ll mi = min(a, min(b, c));
	ll x = a + b + c - mi * 3;
	if (x > k || x % 3 != k % 3) return false;
	ll ma = max(a, max(b, c));
	ll y = ma * 3 - a - b - c;
	if (y > n - k || y % 3 != (n - k) % 3) return false;
	return true;
}

int main() {
	int t; scanf("%d", &t);
	for (; t > 0; t--) {
		ll d1, d2; scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
		if (check(d1, 0, d2) || check(d1, 0, -d2) || check(-d1, 0, d2) || check(-d1, 0, -d2))
			printf("yes\n");
		else
			printf("no\n");
	}
}