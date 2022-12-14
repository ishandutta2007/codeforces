#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 300005;

int n, q, a[MaxN], id[MaxN];
int fenw[MaxN], dat[MaxN], timer;

int get(int r) {
    int ans = 0;
    while (r >= 0) {
        ans += fenw[r];
        r &= r + 1, --r;
    }
    return ans;
}

void upd(int r, int val) {
    while (r < MaxN) {
        fenw[r] += val;
        r |= r + 1;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        id[a[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        if (id[i + 1] < id[i]) {
            upd(i, +1);
        }
    }
    scanf("%d", &q);
    while (q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            printf("%d\n", get(y - 1) - get(x - 1) + 1);
        } else {
            for (int sign = -1; sign <= 1; sign += 2) {
                ++timer;
                for (int it = 0; it < 2; ++it) {
                    if (a[x] < n && dat[a[x]] != timer) {
                        upd(a[x], sign * (id[a[x] + 1] < id[a[x]]));
                        dat[a[x]] = timer;
                    }
                    if (a[x] > 1 && dat[a[x] - 1] != timer) {
                        upd(a[x] - 1, sign * (id[a[x]] < id[a[x] - 1]));
                        dat[a[x] - 1] = timer;
                    }
                    swap(x, y);
                }
                if (sign < 0) {
                    id[a[x]] = y;
                    id[a[y]] = x;
                    swap(a[x], a[y]);
                }
            }
        }
    }
    return 0;
}