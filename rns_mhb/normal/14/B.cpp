#include <bits/stdc++.h>
using namespace std;

#define N 10100

int n, a[N], b[N], x, mn, mx;

int main() {
    scanf("%d%d", &n, &x);
    mn = N;
    mx = 0;
    for(int i = 0; i < n; i ++) {
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
        mn = min(mn, b[i]);
        mx = max(mx, a[i]);
    }

    if(mx > mn) puts("-1");
    else {
        if(mx <= x && x <= mn) puts("0");
        else {
            if(mx > x) printf("%d", mx - x);
            else printf("%d", x - mn);
        }
    }

}