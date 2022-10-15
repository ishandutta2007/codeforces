#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, k, d;
int x[500005];
bool f[500005];
int ftree[500005];

#define lowbit(i) ((i)&(-(i)))

int query(int a)
{
    if (a < 0) return 0;
    int ans = 0;
    while (a) {
        ans += ftree[a]; a -= lowbit(a);
    }
    return ans + 1;
}

void modify(int a)
{
    while (a <= n) {
        ftree[a]++; a += lowbit(a);
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &d);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    sort(x + 1, x + n + 1);
    for (int i = 1; i < k; i++) f[i] = false;
    int interval_begin = 1;
    for (int i = k; i <= n; i++) {
        while (x[i] - x[interval_begin] > d) interval_begin++;
        if (i - interval_begin + 1 < k) {
            f[i] = false;
        } else {
            f[i] = (query(i - k) - query(interval_begin - 2) > 0);
        }
        if (f[i]) modify(i);
        //printf("%d ", f[i] ? 1 : 0);
    }
    printf("%s", f[n] ? "YES" : "NO");
    return 0;
}