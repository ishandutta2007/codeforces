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

//bool first[20][20][20][20][5];

int n;
int a[1005];

int main()
{
    /*for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                for (int k2 = 0; k2 <= 10; k2++) {
                    if (i + j + k + k2 == 0) continue;
                    for (int l = 0; l <= 4; l++) {
                        bool all_first = true;
                        for (int m = 1; m <= 4; m++) {
                            if (m == l) continue;
                            bool is_first; bool good = false;
                            if (m == 1 && i) {
                                good = true; is_first = first[i-1][j][k][k2][m];
                            } else if (m == 2 && j) {
                                good = true; is_first = first[i][j-1][k][k2][m];
                            } else if (m == 3 && k) {
                                good = true; is_first = first[i][j][k-1][k2][m];
                            } else if (m == 4 && k2) {
                                good = true; is_first = first[i][j][k][k2-1][m];
                            }
                            if (good) all_first = all_first && is_first;
                        }
                        if (!all_first) first[i][j][k][k2][l] = true;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= 5; k++) {
                for (int l = 1; l <= 5; l++) {
                    printf("%d %d %d %d: %s\n", i, j, k, l, first[i][j][k][l][0] ? "first" : "second");
                }
            }
        }
    }*/
    int T; scanf("%d", &T);
    for (int d = 1; d <= T; d++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        int tot = 0; int maxv = 0;
        for (int i = 1; i <= n; i++) {
            tot += a[i]; maxv = max(maxv, a[i]);
        }
        if (maxv > tot - maxv) {
            printf("T\n");
        } else {
            printf("%s\n", tot % 2 ? "T" : "HL");
        }
    }
    return 0;
}