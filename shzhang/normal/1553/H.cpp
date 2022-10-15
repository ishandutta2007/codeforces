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

int n, k;
int a[600000];
int ans[600000];
int tmp[600000][20];

vector<int> topv[600000];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) tmp[i][j] = (1 << k);
    }
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int x = 0;
    while (x <= k) {
        int last = -1;
        bool distinct = true;
        for (int i = 1; i <= n; i++) {
            int cur = a[i] >> (k - x);
            if (cur == last) distinct = false;
            last = cur;
        }
        if (distinct) break;
        else x++;
    }
    x--;
    for (int i = 0; i < (1 << k); i++) ans[i] = (1 << k);
    for (int i = 2; i <= n; i++) {
        if ((a[i] >> (k-x)) == (a[i-1] >> (k-x))) {
            for (int j = 0; j < (1 << (k - x)); j++) {
                ans[j] = min(ans[j], max((a[i] ^ j) - (a[i-1] ^ j), (a[i-1] ^ j) - (a[i] ^ j)));
            }
        }
    }
    for (int i = (1 << (k - x)); i < (1 << k); i++) {
        ans[i] = ans[i & ((1 << (k - x)) - 1)];
    }
    for (int i = 1; i <= n; i++) {
        topv[a[i] >> (k - x)].push_back(i);
    }
    /*for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            printf("%d %d %d ", i & ((1 << (j + 1)) - 1), j, tmp[i & ((1 << (j + 1)) - 1)][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < (1 << x); i++) {
        for (int b = 0; b < x; b++) {
            int j = (i ^ ((1 << (b+1)) - 1));
            int xorv = (((j & ((1 << (b+1)) - 1)) ^ (1 << b)) << (k - x));
            //printf("%d %d %d\n", i, j, xorv);
            for (int idx1 = 0; idx1 < topv[i].size(); idx1++) {
                for (int idx2 = 0; idx2 < topv[j].size(); idx2++) {
                    int val1 = a[topv[i][idx1]];
                    int val2 = a[topv[j][idx2]];
                    //printf("%d %d\n", val1, val2);
                    for (int K = 0; K < (1 << (k - x)); K++) {
                        int A = (val1 ^ xorv ^ K);
                        int B = (val2 ^ xorv ^ K);
                        tmp[xorv ^ K][b + k - x] = min(tmp[xorv ^ K][b + k - x], max(A-B, B-A));
                    }
                }
            }
        }
    }
    //fprintf(stderr, "HERE");
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            //printf("%d ", tmp[i & ((1 << (j + 1)) - 1)][j]);
            ans[i] = min(ans[i], tmp[i & ((1 << (j + 1)) - 1)][j]);
        }
        printf("%d ", ans[i]);
    }
    return 0;
}