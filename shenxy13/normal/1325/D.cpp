#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	long long u, v;
	scanf("%lld %lld", &u, &v);
	if ((u & 1) != (v & 1) || u > v) printf("-1");
	else if (u == 0 && v == 0) printf("0");
	else if (u == v) printf("1\n%lld", u);
	else {
		long long a = (v - u) / 2;
		long long x = 0, y = 0;
		for (long long i = 1; i <= 1000000000000000000LL; i <<= 1) {
			if ((a & i) && (u & i)) {
				printf("3\n%lld %lld %lld", a, a, u);
				return 0;
			} else if (a & i) x += i, y += i;
			else if (u & i) x += i;
		}
		printf("2\n%lld %lld", x, y);
	}
	return 0;
}