#include <cstdio>
int Q, tp, d; long long X, K, p[66];
int main() {
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%lld", &tp, &X);
		d = 0;
		while (2LL << d <= X) ++d;
		if (tp <= 2) {
			scanf("%lld", &K);
			K *= -1;
			if (K < 0) K = (1LL << d) - (-K) % (1LL << d);
			K %= (1LL << d);
		}
		if (tp == 1) {
			p[d] = (p[d] + K) % (1LL << d);
		}
		else if (tp == 2) {
			for (int i = d; i <= 60; ++i) {
				p[i] = (p[i] + (K << (i - d))) % (1LL << i);
			}
		}
		else {
			long long cur = X;
			printf("%lld", X);
			while (d > 0) {
				long long pos = X - (1LL << d);
				pos = (pos + (1LL << d) - p[d]) % (1LL << d);
				pos >>= 1;
				--d;
				pos = (pos + p[d]) % (1LL << d);
				X = pos + (1LL << d);
				printf(" %lld", X);
			}
			printf("\n");
		}
	}
	return 0;
}