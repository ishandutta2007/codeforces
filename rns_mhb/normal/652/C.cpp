#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define pb push_back
#define f1(i, a, b) for (int i = a; i <= b; i ++)

int a[N], b[N], c[N];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    int x, y, l = 0;
    f1(i, 1, n) scanf("%d", &a[i]);
    f1(i, 1, n) b[a[i]] = i;
    f1(i, 1, m) {
		scanf("%d %d", &x, &y);
        x = b[x], y = b[y];
        if (x > y) swap(x, y);
        c[y] = max(c[y], x);
    }
    ll ans = 0;
    f1(r, 1, n) {
		l = max(c[r], l);
        ans += r - l;
    }
	printf("%I64d\n", ans);
}