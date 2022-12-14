#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, x, y;

int main() {
    scanf("%d", &n);
    int l = 1, r = n;
    bool ok = false;
    printf("? %d %d\n", l, r);
    fflush(stdout);
    scanf("%d", &x);
    ///
    if (x != 1) {
        printf("? %d %d\n", l, x);
        fflush(stdout);
        scanf("%d", &y);
        if (x == y) ok = true;
    }
    if (!ok) {
        l = x+1, r = n;
        while (l < r) {
            int mid = (l+r) / 2;
            printf("? %d %d\n", x, mid);
            fflush(stdout);
            scanf("%d", &y);
            if (y == x) r = mid; else l = mid+1;
        }
    } else {
        l = 1, r = x-1;
        while (l < r) {
            int mid = (l+r+1) / 2;
            printf("? %d %d\n", mid, x);
            fflush(stdout);
            scanf("%d", &y);
            if (y == x) l = mid; else r = mid-1;
        }
    }
    printf("! %d", l);
}