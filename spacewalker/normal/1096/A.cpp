#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
constexpr ll MOD = 1;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll l, r; scanf("%lld %lld", &l, &r);
		printf("%lld %lld\n", l, 2*l);
	}
	return 0;
}