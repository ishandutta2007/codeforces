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

int n;
int p[4005];
bool f[4005][4005];

void work(void)
{
    vector<int> sizseq;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", p + i);
    }
    int curleft = p[1]; int blksiz = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (p[i] > curleft) {
            sizseq.push_back(blksiz);
            blksiz = 0; curleft = p[i];
        }
        blksiz++;
    }
    if (blksiz) sizseq.push_back(blksiz);
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            f[i][j] = false;
        }
    }
    f[0][0] = true;
    int curtotal = 0;
    for (int i = 0; i < sizseq.size(); i++) {
        for (int j = 0; j <= curtotal; j++) {
            int k = curtotal - j;
            if (f[j][k]) {
                f[j+sizseq[i]][k] = f[j][k+sizseq[i]] = true;
            }
        }
        curtotal += sizseq[i];
    }
    printf("%s\n", f[n][n] ? "YES" : "NO");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}