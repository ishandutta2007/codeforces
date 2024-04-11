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

int T;
int n;
char s[200005];
int f[200005][2][2][5];

char c[] = {'L', 'R'};

void cycshift(void)
{
    char first = s[1];
    for (int i = 1; i < n; i++) {
        s[i] = s[i+1];
    }
    s[n] = first;
}

int main()
{
    scanf("%d", &T);
    for (int d = 1; d <= T; d++) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        int ans = 100000000;
        for (int tim = 1; tim <= 5; tim++) {
            cycshift();
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        for (int l = 1; l <= 2; l++) {
                            f[i][j][k][l] = 100000000;
                        }
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (i == j) {
                        f[1][i][j][1] = (c[i] == s[1] ? 0 : 1);
                    }
                }
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        for (int l = 1; l <= 2; l++) {
                            int& cur = f[i][j][k][l];
                            int& nxtL = f[i+1][j][0][k == 0 ? l + 1 : 1];
                            int& nxtR = f[i+1][j][1][k == 1 ? l + 1 : 1];
                            nxtL = min(nxtL, cur + (s[i+1] == 'L' ? 0 : 1));
                            nxtR = min(nxtR, cur + (s[i+1] == 'R' ? 0 : 1));
                        }
                    }
                }
            }
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 1; l <= 2; l++) {
                        if (j != k) {
                            ans = min(ans, f[n][j][k][l]);
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}