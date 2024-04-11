#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 1000006

int ps, p[N/10];
int n;
bool vis[N];

bool check(int n) {
    if (n < N) {
		if (!vis[n]) return 1;
		return 0;
    }
    int m = sqrt(n);
    f1(i, 2, m) if (n % i == 0) return 0;
    return 1;
}

int func(int n) {
    if (check(n)) return 1;
    int res = 0;
    if (n % 2 == 0) return 2;
	if (check(n - 2)) return 2;
	return 3;
}

int main() {
	f0(i, 2, 1002) if (!vis[i]) {
        p[ps ++] = i;
        for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
	f0(i, 1003, N) if (!vis[i]) p[ps ++] = i;
	scanf("%d", &n);
	int ans = func(n);
	printf("%d\n", ans);
	return 0;
}