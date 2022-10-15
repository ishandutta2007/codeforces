#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int n;

int minpos[300005];
int maxpos[300005];
int prefixmax[300005];
int suffixmax[300005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if (minpos[a]) {
            minpos[a] = min(minpos[a], i);
            maxpos[a] = max(maxpos[a], i);
        } else {
            minpos[a] = maxpos[a] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (maxpos[i]) prefixmax[i] = max(prefixmax[i-1], maxpos[i]);
        else prefixmax[i] = prefixmax[i-1];
    }
    for (int i = n; i >= 1; i--) {
        suffixmax[i] = max(suffixmax[i+1], maxpos[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        /* i is the color of the left end. */
        int left = minpos[i];
        if (!left) continue;
        int right = max(prefixmax[i-1], suffixmax[i+1]);
        ans = max(ans, right-left);
    }
    printf("%d", ans);
    return 0;
}