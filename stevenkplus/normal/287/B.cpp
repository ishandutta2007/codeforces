#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll go(int K) {
	return ll(K) * (K - 1) / 2;
}

ll N;
int K;
bool test(int k) {
	ll p = go(K);
	ll q = go(K - k);
	return p - q + 1 >= N;
}

int main() {
	cin >> N >> K;
	int lo = 0;
	int hi = K - 1;
	if (!test(hi)) {
		printf("-1\n");
		return 0;
	}
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}

	printf("%d\n", lo);
	return 0;
}