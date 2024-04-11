#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdint>
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

int n, q;
int a[25005];
int pos[25005];
int l[100005], r[100005];
uint16_t* first_inc[25005];
bool* first_inc_high[25005];
vector<int> op[25005];
int minv[25005];
int ans[100005];

static inline void set_first_inc(int L, int R, int val)
{
    first_inc[L][R-L] = val;
    first_inc_high[L][R-L] = (val >= 65536);
}

static inline int get_first_inc(int L, int R)
{
    return (int)first_inc[L][R-L] + 65536 * (int)first_inc_high[L][R-L];
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pos[a[i]] = i;
        minv[i] = q + 1;
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", l + i, r + i);
        op[l[i]].push_back(i);
    }
    first_inc[0] = new uint16_t[n + 2];
    first_inc_high[0] = new bool[n + 2];
    for (int i = 0; i <= n + 1; i++) set_first_inc(0, i, q + 1);
    for (int i = 1; i <= n; i++) {
        first_inc[i] = new uint16_t[n - i + 2];
        first_inc_high[i] = new bool[n - i + 2];
        for (int j = 0; j < op[i].size(); j++) {
            int opv = op[i][j];
            minv[r[opv]] = min(minv[r[opv]], opv);
        }
        int cur = q + 1;
        for (int j = n; j >= i; j--) {
            cur = min(cur, minv[j]);
            set_first_inc(i, j, cur);
            //printf("%d %d: %d\n", i, j, (int)first_inc[i][j - i]);
        }
        set_first_inc(i, n + 1, q + 1);
        first_inc[i][n - i + 1] = q + 1;
    }
    for (int i = 1; i <= n; i++) {
        int lmax = 0, rmin = n + 1;
        for (int val = a[i] + 1; val <= n; val++) {
            int j = pos[val];
            if (i <= j) {
                if (rmin > j) {
                    //printf("%d %d: %d %d\n", i, j, first_inc[i][j-i], min(first_inc[i][rmin - i], first_inc[lmax][j - lmax]));
                    ans[get_first_inc(i, j)]++;
                    ans[min(get_first_inc(i, rmin), get_first_inc(lmax, j))]--;
                    rmin = j;
                }
            } else {
                if (lmax < j) {
                    //printf("%d %d: %d %d\n", i, j, first_inc[j][i-j], min(first_inc[j][rmin - j], first_inc[lmax][i - lmax]));
                    ans[get_first_inc(j, i)]++;
                    ans[min(get_first_inc(j, rmin), get_first_inc(lmax, i))]--;
                    lmax = j;
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        ans[i] += ans[i-1];
        printf("%d\n", ans[i]);
    }
    return 0;
}