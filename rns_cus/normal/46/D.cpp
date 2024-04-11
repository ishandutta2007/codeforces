#include <bits/stdc++.h>
using namespace std;

#define N 100100

int l, b, f, n, m, p[N], len[N];
bool vis[N];

int main() {
//    freopen("1.in", "r", stdin);
    scanf("%d %d %d %d", &l, &b, &f, &n);
    for (int id = 1; id <= n; id ++) {
        int ty, x;
        scanf("%d %d", &ty, &x);
        if (ty == 1) {
            len[id] = x; p[id] = -1;
            for (int i = 0, j = 0; i < l; i = j) {
                while (j < l && vis[j]) j ++;
                i = j;
                while (j < l && !vis[j]) j ++;
                int y = x;
                if (i > 0) y += b;
                if (j < l) y += f;
                if (j - i < y) continue;
                y = i;
                if (i > 0) y += b;
                p[id] = y;
                for (int k = y; k < y + x; k ++) vis[k] = 1;
                break;
            }
            printf("%d\n", p[id]);
        }
        else {
            for (int k = 0; k < len[x]; k ++) vis[p[x]+k] = 0;
        }
    }
}