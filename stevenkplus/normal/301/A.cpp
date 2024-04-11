#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200100;

int N;
int ar[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < 2 * N - 1; ++i) {
		scanf("%d", ar + i);
	}

	sort(ar, ar + 2 * N - 1);
	int sum = 0;

	if (N % 2 == 0) {
		for(int i = 0; i + 1 < 2 * N - 1; i += 2) {
			int s = ar[i] + ar[i + 1];
			if (s < 0) sum -= s;
			else sum += s;
		}
		sum += ar[2 * N - 2];
	} else {
		for(int i = 0; i < 2 * N - 1; ++i) {
			if (ar[i] < 0) sum -= ar[i];
			else sum += ar[i];
		}
	}

	printf("%d\n", sum);
	return 0;
}