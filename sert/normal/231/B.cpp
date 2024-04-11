#include <cstdio>
#include <iostream>
#include <cstring>

#define ff first
#define ss second

const int N = 134;

using namespace std;

int n, l, d;
int mn, mx;

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%d %d %d", &n, &d, &l);

    for (int i = 0; i < n; i++) {
        mx += (i % 2 ? -1 : l);
        mn += (i % 2 ? -l : 1);
    }

    if (d < mn || d > mx) {
        printf("-1\n");
        return 0;
    }

    mn = d;

    for (int i = 0; i < n; i++) {
        if (mx - mn == 0) {
            printf("%d ", (i % 2 ? 1 : l));
            continue;
        }
        if (mx - mn >= l - 1) {
            printf("%d ", (i % 2 ? l : 1));
            mn += (l - 1);
            continue;
        }
        d = mx - mn;
        printf("%d ", (i % 2) ? 1 + d : l - d);
        mn = mx;
    }

    return 0;
}