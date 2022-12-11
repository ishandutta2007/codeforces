#include <bits/stdc++.h>

using namespace std;

int query(int i) {
    printf("? %d\n", i + 1);
    fflush(stdout);
    int ans; scanf("%d", &ans);
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        // split into two: [lo, mid] and [mid + 1, h]
        int v1 = query(mid), v2 = query(mid + 1);
        if (v1 < v2) hi = mid;
        else lo = mid + 1;
    }
    printf("! %d\n", lo + 1);
    fflush(stdout);
}