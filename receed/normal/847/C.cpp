#include <bits/stdc++.h>

using namespace std;

void f(int n, long long k) {
	if (n == 0)
		return;
	if (k < n - 1) {
        printf("()");
        f(n - 1, k);
        return;
    }
    printf("(");
    f(n - 1, k - n + 1);
    printf(")");
}

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	if (k > (long long) n * (n - 1) / 2)
		printf("Impossible");
	else
		f(n, k);
}