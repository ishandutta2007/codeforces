#include <bits/stdc++.h>
using namespace std;
#define M 3000100

int n;
int m;
int f[M], a[M];

int main() {
	//freopen("A2.in", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		f[i] = f[i-1] + (!a[i]);
	}
	int s = -1;
	int I, J;
	for (int j = 0, i = 1; i <= n; i++) {
		while (f[i] - f[j] > m) j++;
		if (s < i - j) {
            s = i - j;
			I = j + 1;
			J = i;
		}
	}
	printf("%d\n", s);
	for (int i = 1; i <= n; i++) {
		if (I <= i && i <= J) {
			a[i] = 1;
		}
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}