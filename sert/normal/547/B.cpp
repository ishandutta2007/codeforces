#include <cstdio>
#include <set>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
const int N = 2e5 + 34;
std::set<std::pair<int, int> > s1, s2;
int a[N], ans[N];
int t[N][19];
int n, d[N];
int getmin(int l, int r) {
    return min(t[l][d[r - l]], t[r - (1 << (d[r - l]))][d[r - l]]);
}
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++)
        t[i][0] = a[i];
    for (int i = 1; i < 18; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            t[j][i] = min(t[j][i - 1], t[j + (1 << (i - 1))][i - 1]);
    for (int i = 3; i <= n; i++)
        d[i] = d[(i + 1) / 2] + 1;
    int l, r, m, p1, p2;
    for (int i = 0; i < n; i++) {
        l = 0;
        r = i + 1;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (getmin(i - m, i + 1) >= a[i])
                l = m;
            else
                r = m;
        }
        p1 = l;
        l = 0;
        r = n - i;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (getmin(i, i + m + 1) >= a[i])
                l = m;
            else
                r = m;
        }
        p2 = l;
        ans[p1 + p2 + 1] = max(ans[p1 + p2 + 1], a[i]);
        //printf("%d %d \n", p1, p2);
    }

    for (int i = n; i > 1; i--)
        ans[i - 1] = max(ans[i - 1], ans[i]);

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);


    return 0;
}