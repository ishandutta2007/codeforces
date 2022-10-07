#include <cstdio>

using namespace std;

const int MAXN = 2001000;

char A[MAXN], B[MAXN];

int N;

int go() {
	scanf("%d", &N);
	scanf("%s", A);
	scanf("%s", B);

	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 2 * N; ++i) {
		if (A[i] == '1' && B[i] == '1') ++c;
		else if (A[i] == '1') ++a;
		else if (B[i] == '1') ++b;
	}

	a -= b;
	c %= 2;
	if (c == 1) {
		if (a >= 0) return 1;
		else if (a == -1 || a == -2) return 0;
		else return -1;
	} else {
		if (a > 0) return 1;
		else if (a == 0 || a == -1) return 0;
		else return -1;
	}
}

int main() {
	int ans = go();
	if (ans == -1) printf("Second\n");
	else if (ans == 0) printf("Draw\n");
	else printf("First\n");
	return 0;
}