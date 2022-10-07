#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXS = 100;

ll s(ll x) {
	ll sum = 0;
	while (x > 0) {
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

ll squareroot(ll x) {
	if (x < 0) {
		return 0;
	}
	double d = sqrt(x);
	return int(d);
}

int main() {
	ll N;
	scanf("%I64d", &N);
	ll maxX = squareroot(N);
	ll minX = squareroot(N - maxX * MAXS);
	ll x;
	for(x = minX; x <= maxX; ++x) {
		if (x * x + s(x) * x == N) {
			break;
		}
	}
	if (x > maxX) {
		x = -1;
	}
	int ans = int(x);
	printf("%d\n", ans);
	return 0;
}