#include <cstdio>

using namespace std;

const int MAXN = 10100;

char A[MAXN], B[MAXN];

int main() {
	scanf("%s", A);
	scanf("%s", B);

	int a = 0, b = 0;
	for(int i = 0; A[i]; ++i) {
		if (A[i] == '1') ++a;
	}
	for(int i = 0; B[i]; ++i) {
		if (B[i] == '1') ++b;
	}

	if (a % 2 == 1) ++a;
	if (a >= b) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}