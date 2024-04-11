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
int a[200005];
int freq[200005];
int psum[200005];
int left[400005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); freq[a[i]]++;
    }
    int maxval = 0; int mode = 0; bool dup = false;
    for (int i = 1; i <= n; i++) {
        if (freq[i]) {
            maxval = i;
            if (freq[i] > freq[mode]) {
                mode = i; dup = false;
            } else if (freq[i] == freq[mode]) {
                dup = true;
            }
        }
    }
    if (dup) {
        printf("%d", n); return 0;
    }
    int ans = 0;
    for (int v = 1; v <= maxval; v++) {
        if (v == mode) continue;
        for (int i = 0; i <= 2 * n; i++) left[i] = -1;
        left[n] = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == mode) {
                psum[i] = psum[i-1] + 1;
            } else if (a[i] == v) {
                psum[i] = psum[i-1] - 1;
            } else {
                psum[i] = psum[i-1];
            }
            if (left[psum[i] + n] != -1) {
                ans = max(ans, i - left[psum[i] + n]);
            } else {
                left[psum[i] + n] = i;
            }
        }
    }
    printf("%d", ans);
    return 0;
}