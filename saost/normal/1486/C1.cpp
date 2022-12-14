#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, x, y;

int main() {
    scanf("%d", &n);
    int l = 1, r = n;
    while (l < r-2) {
            int mid = (l + r) / 2;
        if (!x) {
            printf("? %d %d\n", l, r);
            fflush(stdout);
            scanf("%d", &x);
        }

        if (x <= mid) {
            printf("? %d %d\n", l, mid);
            fflush(stdout);
            scanf("%d", &y);
            if (x == y) r = mid; else l = mid + 1, x = 0;
        } else {
            printf("? %d %d\n", mid+1, r);
            fflush(stdout);
            scanf("%d", &y);
            if (x == y) l = mid+1; else r = mid, x = 0;
        }
    }
    if (l == r-2) {
        if (!x) {
            printf("? %d %d\n", l, r);
            fflush(stdout);
            scanf("%d", &x);
        }
        printf("? %d %d\n", l, r-1);
        fflush(stdout);
        scanf("%d", &y);
        if (x == y) {
            if (x == l) l++;
        } else {
            if (x == r) {
                if (y == l) l++;
            } else l = r;
        }
    } else if (l == r-1) {
        if (!x) {
            printf("? %d %d\n", l, r);
            fflush(stdout);
            scanf("%d", &x);
        }
        if (l == x) l++;
    }
    printf("! %d", l);
}