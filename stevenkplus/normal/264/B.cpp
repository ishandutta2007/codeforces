#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
#define pb push_back
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;
const int MAXP = 10100;

vi primes;
int tmp[MAXN];

void sieve() {
	tmp[0] = tmp[1] = true;
	for(int i = 2; i < MAXN; ++i) {
		if (!tmp[i]) {
			primes.pb(i);
			for(int j = i; j <= (MAXN - 1) / i; ++j) {
				tmp[j * i] = true;
			}
		}
	}
}

int N;

vi facs[MAXN];
int ar[MAXN];

void prec() {
	sieve();
	for(int i = 0; i < N; ++i) {
		int c = ar[i];
		int j = 0;
		while (true) {
			int p = primes[j];
			if (c % p == 0) {
				facs[i].pb(j);
			}
			while (c % p == 0) {
				c /= p;
			}
			if (c == 1) break;
			if (p * p > c) {
				j = int(lower_bound(primes.begin(), primes.end(), c) -
						primes.begin());
			} else {
				++j;
			}
		}
	}
}

int ans[MAXP];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	prec();
	int fin = 0;

	for(int i = 0; i < N; ++i) {
		int m = 0;
		repi(j, facs[i]) {
			m = max(m, ans[*j]);
		}

		fin = max(fin, m + 1);
		repi(j, facs[i]) {
			ans[*j] = max(ans[*j], m + 1);
		}
	}
	printf("%d\n", fin);
	return 0;
}