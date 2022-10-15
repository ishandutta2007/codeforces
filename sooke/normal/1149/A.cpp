#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

int n, cnt[3];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        cnt[read()]++;
    }
    if (cnt[2]) {
        cnt[2]--;
        printf("2 ");
        if (cnt[1]) {
            cnt[1]--; printf("1 ");   
        }
        for (; cnt[2]; cnt[2]--) {
            printf("2 ");
        }
        for (; cnt[1]; cnt[1]--) {
            printf("1 ");
        }
    } else {
        for (int i = 1; i <= n; i++) {
            printf("1 ");
        }   
    }
    return 0;
} // sooke