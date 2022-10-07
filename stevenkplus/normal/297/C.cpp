#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 100100;

pii ar[MAXN];
int A[MAXN],B[MAXN];

int N;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", &(ar[i].first));
		ar[i].second = i;
	}

	sort(ar, ar + N);

	int third = (N + 2) / 3;
	for(int i = 0; i < third; ++i) {
		int k = ar[i].second;
		A[k] = 0;
		B[k] = ar[i].first;
	}

	int a = 0, b = 0;
	for(int i = third; i < N; ++i) {
		int k = ar[i].second;
		if (i % 2 == 0) {
			A[k] = a++;
			B[k] = ar[i].first - A[k];
		} else {
			B[k] = b++;
			A[k] = ar[i].first - B[k];
		}
	}

	printf("YES\n");
	for(int i = 0; i < N; ++i) {
		if (i) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	for(int i = 0; i < N; ++i) {
		if (i) printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");
	return 0;
}