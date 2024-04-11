#include <cstdio>
#include <map>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef long long ll;

const int MAXN = 100100;

int N, MOD;

int A[MAXN], B[MAXN];

map<int, int> cnts;

int main() {
	scanf("%d", &N);
	int repeats = 0;

	for(int i = 0; i < N; ++i) {
		scanf("%d", A + i);
		++cnts[A[i]];
	}
	for(int i = 0; i < N; ++i) {
		scanf("%d", B + i);
		++cnts[B[i]];
		if (B[i] == A[i]) {
			++repeats;
		}
	}
	scanf("%d", &MOD);

	int num2 = 0;
	ll prod = 1;
	repi(i, cnts) {
		for(int j = 1; j <= i -> second; ++j) {
			int fac = j;
			while (fac % 2 == 0) {
				++num2;
				fac /= 2;
			}
			(prod *= fac) %= MOD;
		}
	}

	num2 -= repeats;
	for(int i = 0; i < num2; ++i) {
		(prod *= 2) %= MOD;
	}

	int ans = int(prod);
	printf("%d\n", ans);
	return 0;
}