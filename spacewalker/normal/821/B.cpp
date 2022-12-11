#include <cstdio>
#include <algorithm>

typedef long long ll;
using namespace std;
ll value(ll x, ll y) {
	return (x + 1) * (y + 1) * (x + y) / 2;
}

int main() {

	int m, b; scanf("%d %d", &m, &b);
	ll bestVal = 0;
	for (int urcy = b; urcy >= 0; --urcy) {
		// find the optimal x-coordinate
		int urcx = (ll)m * (b - urcy);
		bestVal = max(bestVal, value(urcx, urcy));
		//printf("(%d, %d) has value %lld\n", urcx, urcy, value(urcx, urcy));
	}
	printf("%I64d", bestVal);
	return 0;
}