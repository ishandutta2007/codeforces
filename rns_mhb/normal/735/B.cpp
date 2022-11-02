#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 100005

int a[N];
int n, n1, n2;

int main() {
	scanf("%d", &n);
    scanf("%d %d", &n1, &n2);
	f1(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
    if (n1 > n2) swap(n1, n2);
    ll s1 = 0, s2 = 0;
    for (int i = n, j = 0; j < n1; i --, j ++) s1 += a[i];
    for (int i = n - n1, j = 0; j < n2; i --, j ++) s2 += a[i];
    double ans = 1.0 * s1 / n1 + 1.0 * s2 / n2;
    printf("%.7lf\n", ans);
	return 0;
}