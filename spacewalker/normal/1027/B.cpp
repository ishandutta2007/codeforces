#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

ll answerEven(ll n, ll i, ll j) {
	// printf("extra %lld\n", (j/2 + j%2));
	return ((i + j) % 2 == 1 ? n*n/2 : 0) + (i - 1) * n/2 + (j/2 + j%2);
}

ll answerOdd(ll n, ll i, ll j) {
	ll thing = (i - ((i + j) % 2 == 0 ? 1 : 2));
	ll oddRowsBefore = max(0LL, thing / 2 + thing % 2);
	ll evenRowsBefore = i - 1 - oddRowsBefore;
	ll addCells = (j / 2 + j % 2);
	// printf("AC %lld or %lld ar %lld\n", addCells, oddRowsBefore, evenRowsBefore);
	return ((i + j) % 2 == 1 ? n*n/2 + 1 : 0) + (n + 1)/2 * oddRowsBefore + (n - 1)/2 * evenRowsBefore
		+ addCells;
}

int main() {
	ll n; int q; scanf("%lld %d", &n, &q);
	while (q--) {
		int x, y; scanf("%d %d", &x, &y);
		printf("%lld\n", (n % 2 == 0 ? answerEven(n, x, y) : answerOdd(n, x, y)));
	}
	return 0;
}