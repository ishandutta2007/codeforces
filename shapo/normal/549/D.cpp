#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXL = 108;

int n, m;
char f[MAXL][MAXL];
int ans;
int val[MAXL][MAXL];

int
main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", f[i]);
    }
    ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int cur_val = val[i + 1][j] + val[i][j + 1] - val[i + 1][j + 1];
            int exp_val = (f[i][j] == 'W') ? 1 : -1;
            int diff = exp_val - cur_val;
            if (diff) {
                // fprintf(stderr, "%d %d -> %d\n", i, j, diff);
                // fflush(stdout);
                ans++;
            }
            val[i][j] = diff;
            val[i][j] += val[i + 1][j] + val[i][j + 1] - val[i + 1][j + 1];
        }
    }
    printf("%d\n", ans);
    return 0;
}