#include <bits/stdc++.h>
using namespace std;

#define N 105
#define INF 1000000

template <class T> void chkmin(T &a, T b) { if (a > b) a = b; }

int n, d, ans;
int x[N], a[N], s[N];

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &x[i]);
        a[x[i]] ++;
    }
    for (int i = 1; i <= 100; i ++) s[i] = s[i-1] + a[i];
    ans = INF;
    if (d == 100) d --;
    for (int i = 1; i + d <= 100; i ++) {
        chkmin(ans, n - (s[i+d] - s[i-1]));
    }
    printf("%d\n", ans);
	return 0;
}