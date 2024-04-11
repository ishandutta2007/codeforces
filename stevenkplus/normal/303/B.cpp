#include <cstdio>

int N, M, X, Y, A, B;

int gcf(int a, int b) {
	if (b == 0) return a;
	return gcf(b, a % b);
}

int main() {
	scanf("%d %d %d %d %d %d", &N, &M, &X, &Y, &A, &B);
	int k = gcf(A, B);
	A /= k;
	B /= k;

	int s1 = N / A;
	int s2 = M / B;
	if (s1 > s2) s1 = s2;
	A *= s1;
	B *= s1;

	int x = X - (A + 1) / 2;
	if (x < 0) x = 0;
	if (x > N - A) x = N - A;

	int y = Y - (B + 1) / 2;
	if (y < 0) y = 0;
	if (y > M - B) y = M - B;

	printf("%d %d %d %d\n", x, y, x + A, y + B);
	return 0;
}