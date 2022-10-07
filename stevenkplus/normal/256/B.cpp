#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tri(ll x) {
	return x * (x + 1) / 2;
}
ll out(ll a, ll b) {
	ll stick = a - b;
	if (stick > 0) {
		return stick * stick;
	} else {
		return 0;
	}
}

ll cORRn(ll t, ll a, ll b) {
	ll k = t - 1 - (a + b);
	if (k > 0) {
		return tri(k);
	} else {
		return 0;
	}
}

int N, x, y, c;
ll comp(ll t) {
	ll tot = 4 * tri(t) + 1;
	ll ol = out(t, y - 1);
	ll ou = out(t, x - 1);
	ll ORR = out(t, N - y);
	ll od = out(t, N - x);
	ll c1 = cORRn(t, y - 1, x - 1);
	ll c2 = cORRn(t, x - 1, N - y);
	ll c3 = cORRn(t, N - y, N - x);
	ll c4 = cORRn(t, N - x, y - 1);
	return tot - ol - ou - ORR - od + c1 + c2 + c3 + c4;
}

int main() {
	scanf("%d %d %d %d", &N, &x, &y, &c);
	int low = 0;
	int high = 2 * N;
	while (low < high) {
		int mid = (low + high) / 2;
		if (comp(mid) >= c) {
			high = mid;
		} else {
			low = mid + 1; 
		}
	}
	printf("%d\n", low);
	return 0;
}