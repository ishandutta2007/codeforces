#include <cstdio>

using namespace std;

typedef long long ll;

int K, B, N, T;

ll go(ll k) {
	return k * K + B;
}

int main() {
	scanf("%d %d %d %d", &K, &B, &N, &T);

	ll cur = 1;
	int time = 0;
	while (go(cur) <= T) {
		cur = go(cur);
		++time;
	}

	int ans = N - time;
	if (ans < 0) ans = 0;

	printf("%d\n", ans);
	return 0;
}