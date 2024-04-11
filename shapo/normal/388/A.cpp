#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1000

int n;
int a[maxn];
int res;

int
main(int argc, char **argv)
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    reverse(a, a + n);
    int l = 0, r = n + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            int cnt = 0;
            for (int j = i + m; j < n; j += m) {
                ++cnt;
            }
            if (cnt > a[i]) {
                ok = false;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%d\n", r);
    return 0;
}