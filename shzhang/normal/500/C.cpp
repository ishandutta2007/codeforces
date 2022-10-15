#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

int stk[505];
int n, m;
int w[505];
int b[1005];

bool placed[505];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", w + i);
    }
    int stkcur = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d", b + i);
        if (!placed[b[i]]) {
            stk[stkcur] = b[i];
            stkcur++; placed[b[i]] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int j;
        for (j = 1; j <= n; j++) {
            if (stk[j] == b[i]) break;
            ans += w[stk[j]];
        }
        for (int k = j; k >= 2; k--) {
            stk[k] = stk[k-1];
        }
        stk[1] = b[i];
    }
    printf("%d", ans);
    return 0;
}