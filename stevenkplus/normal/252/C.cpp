#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

ll choose2(ll a) {
	return a * (a - 1) / 2;
}


int N, D;

int ar[MAXN];

int main() {
	scanf("%d %d", &N, &D);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	int end = 0;
	ll sum = 0;
	for(int i = 0; i < N; ++i) {
		while (end < N && ar[end] - ar[i] <= D) {
			end++;
		}
		end--;
		int numc = end - i;
		sum += choose2(numc);
	}
	printf("%I64d\n", sum);
	return 0;
}