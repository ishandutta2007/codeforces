#include <cstdio>

using namespace std;

const int MAXN = 100100;
int N;

int ar[MAXN];

int main() {
	scanf("%d", &N);
	int sum = 0;
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
		sum += ar[i];
	}
	printf("%d\n",(sum % N == 0) ? N : N - 1);
	return 0;
}