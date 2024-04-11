#include <bits/stdc++.h>
using namespace std;
#define M 500500
typedef long long ll;

int n, p;
ll a[M];
char s[M];
ll A[M];
ll B[M];
ll answer;

void calc() {
	for (int i = 1; i <= n; i++) {
		A[i] = A[i-1] + a[i];
		B[i] = B[i-1];
		if (s[i] == 'B') {
			B[i] += a[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		ll t = max(B[i], A[i] - B[i]) + B[n] - B[i];
		answer = max(answer, t);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", a + i);
	}
	scanf("%s", s + 1);

	answer = 0;
	calc();
	reverse(a + 1, a + n + 1);
	reverse(s + 1, s + n + 1);
	calc();
	printf("%I64d\n", answer);
	return 0;
}