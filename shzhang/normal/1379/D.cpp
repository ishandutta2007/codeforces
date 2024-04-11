#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int tim[200005];
int tim2[200005];

    int n, h, m, k;

int query(int L, int R)
{
    int l = 0; int r = 2 * n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (tim[mid] <= L) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int left = l;
    l = 0; r = 2 * n;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (tim[mid] >= R) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    //printf("%d %d %d\n", L, R, l - left + 1);
    return l - left + 1;
}

int main()
{
    tim[0] = -1;
    scanf("%d%d%d%d", &n, &h, &m, &k);
    m /= 2;
    for (int i = 1; i <= n; i++) {
        int H, M; scanf("%d%d", &H, &M);
        tim[i] = M % m; tim[n + i] = tim[i] + m;
        tim2[i] = tim[i]; tim2[n + i] = tim[n + i];
    }
    sort(tim + 1, tim + 2 * n + 1);
    int mincnt = n;
    for (int i = 1; i <= n; i++) {
        mincnt = min(mincnt, query(tim[i], tim[i] + k));
    }
    for (int i = 1; i <= n; i++) {
        if (query(tim[i], tim[i] + k) == mincnt) {
            printf("%d %d\n", mincnt, (tim[i] + k) % m);
            for (int j = 1; j <= 2 * n; j++) {
                if (tim2[j] > tim[i] && tim2[j] < tim[i] + k) {
                    printf("%d ", (j > n ? j - n : j));
                }
            }
            break;
        }
    }
    return 0;
}