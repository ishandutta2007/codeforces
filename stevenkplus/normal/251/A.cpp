#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

int ar[MAXN];

int N, D;

ll choose2(ll a) {
	return a * (a - 1) / 2;
}

int main() {
	scanf("%d %d", &N, &D);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	ll sum = 0;
	int prv = 0;
	for(int i = 0; i < N; ++i) {
		while (prv < N && ar[prv] - ar[i] <= D) {
			++prv;
		}
		int num = prv - i - 1;
		sum += choose2(num);
	}

	printf("%I64d\n", sum);
	return 0;
}