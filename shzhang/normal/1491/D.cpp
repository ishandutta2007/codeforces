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

int main()
{
    int q; scanf("%d", &q);
    for (int qr = 1; qr <= q; qr++) {
        int u, v; scanf("%d%d", &u, &v);
        if (u > v) {
            printf("NO\n"); continue;
        }
        int psum = 0;
        for (int i = 0; i < 30; i++) {
            bool a = (bool)(u & (1 << i));
            bool b = (bool)(v & (1 << i));
            if (a && (!b)) {
                psum++;
            } else if ((!a) && b) {
                psum--;
            }
            if (psum < 0) {
                printf("NO\n"); goto loop_end;
            }
        }
        printf("YES\n");
        loop_end:
        ;
    }
    return 0;
}