#include <bits/stdc++.h>
using namespace std;
int n, m, use[1010];
bool prime(int x) {
	for (int i = 2; i < x; i++) if (x % i == 0) return 0;
	return 1;
}
int main() {
//	freopen("A.in", "r", stdin);
	scanf("%d", &n);
	if (n == 1) return puts("0"), 0;
    for (int i = 2; i <= n; i++) {
        if (prime(i)) {
        	int j = i;
        	while (j <= n) {use[m++] = j; j *= i;}
        }
    }
    printf("%d\n", m);
    for (int i = 0; i < m; i++) printf("%d ", use[i]);
}