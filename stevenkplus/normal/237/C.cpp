#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1001100;
const int MAXP = 100100;
bool p[MAXN];
int primes[MAXP];
int primecnt;
void sieve() {
	p[0] = p[1] = true;
	for(int i = 2; i < MAXN; ++i) {
		if (!p[i]) {
			primes[primecnt++] = i;
			for(int x = i; x <= (MAXN - 1) / i; ++x) {
				p[i * x] = true;
			}
		}
	}
}

int main() {
	sieve();
	int a,b,k;
	scanf("%d %d %d", &a, &b, &k);
	int pr = -1;
	int maxl = -1;
	for(int i = 0; i + k - 1 < primecnt; ++i) {
		if (primes[i] >= a) {
			int low = max(pr, a);
			int need = min(primes[i + k - 1], b + 1);
			int l = need - low + 1;
			maxl = max(l, maxl);
		}
		pr = primes[i] + 1;
	}
	if (maxl > b - a + 1) {
		maxl = -1;
	}
	printf("%d\n", maxl);
	return 0;
}