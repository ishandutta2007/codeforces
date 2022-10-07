#include <cstdio>

using namespace std;

int N, M, A, B;

int getrow(int n) {
	return (n - 1) / M;
}

int getcol(int n) {
	return (n - 1) % M;
}

int solve() {
	int ar = getrow(A);
	int br = getrow(B);
	int ac = getcol(A);
	int bc = getcol(B);
	if (ar == br) {
		return 1;
	} else if (ac == 0) {
		if (bc == M - 1 || B == N) {
			return 1;
		} else {
			return 2;
		}
	} else if (bc == M - 1) {
		return 2;
	} else if (ac == bc + 1 || B == N) {
		return 2;
	} else if (ar + 1 == br) {
		return 2;
	} else {
		return 3;
	}
}

int main() {
	scanf("%d %d %d %d", &N, &M, &A, &B);
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}