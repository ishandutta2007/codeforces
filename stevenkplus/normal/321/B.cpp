#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int N, M;

int A[MAXN];
int B[MAXN];
int a = 0, b = 0;
int ar[MAXN];

int maxatk() {
	int best = 0;
	for(int i = 0; i <= a && i <= M; ++i) {
		int off = M - i;
		int sum = 0;
		for(int j = 0; j < i; ++j) {
			if (ar[j + off] < A[j]) {
				sum = 0;
				break;
			}
			sum += ar[j + off] - A[j];
		}
		if (sum > best) best = sum;
	}
	return best;
}

int maxdef() {
	int sum = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	while (x < M) {
		if (z < b && ar[x] > B[z]) {
			++z;
		} else if (y < a && ar[x] >= A[y]) {
			sum += ar[x] - A[y];
			++y;
		} else {
			sum += ar[x];
		}
		++x;
	}
	if (y == a && z == b) {
		return sum;
	} else return 0;
}

char tmp[123];
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		int x;
		scanf("%s %d", tmp, &x);
		if (tmp[0] == 'A') {
			A[a] = x;
			++a;
		} else {
			B[b] = x;
			++b;
		}
	}

	for(int i = 0; i < M; ++i) {
		scanf("%d", ar + i);
	}

	sort(A, A + a);
	sort(B, B + b);
	sort(ar, ar + M);

	int x = maxatk();
	int y = maxdef();

	if (x > y) printf("%d\n", x);
	else printf("%d\n", y);
	return 0;
}