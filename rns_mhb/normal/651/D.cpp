#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}

#define N 500005
char s[N];

int n, a, b, T, t[N], u[N], v[N];

int main() {
    scanf("%d %d %d %d", &n, &a, &b, &T);
    scanf("%s", s+1);
    int ans = 0;
    t[1] = 1;
    if (s[1] == 'w') t[1] += b;
    if (t[1] <= T) chkmax(ans, 1);
    f1(i, 2, n) {
        t[i] = t[i-1] + 1 + a;
        if (s[i] == 'w') t[i] += b;
        if (t[i] <= T) chkmax(ans, i);
    }
    u[n+1] = 1;
	if (s[1] == 'w') u[n+1] += b;
    if (u[n+1] <= T) chkmax(ans, 1);
    f3(i, n, 2) {
        u[i] = u[i+1] + 1 + a;
        if (s[i] == 'w') u[i] += b;
        if (u[i] <= T) chkmax(ans, n + 2 - i);
    }
    u[1] = t[1];
    f1(i, 1, n) v[i] = u[n+2-i];
    int x, y;
    if (ans == n) {
        printf("%d\n", ans);
        return 0;
    }
    f1(i, 1, n) {
        if (t[i] + (i-1) * a > T) break;
        x = T - (i-1) * a - t[i];
		y = lower_bound(v+2, v+n+1, x + v[1] + 1) - v;
        y --;
        if (y == 1) continue;
        y = n + 2 - y;
        chkmax(ans, n - y + 1 + i);
    }
    f1(i, 1, n) {
        if (v[i] + (i-1) * a > T) break;
        if (i == 1) continue;
        x = T - v[i] - (i-1) * a;
        y = lower_bound(t + 2, t + n + 1, x + t[1] + 1) - t;
        y --;
        if (y == 1) continue;
		chkmax(ans, i + y - 1);
    }
    printf("%d\n", ans);
	return 0;
}