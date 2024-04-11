#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <map>
using namespace std;
const int N = 1000000 + 10;
int mx[N][22], mx2[N][22];
int n, a[N], lg[N], pre[N];

int quemx(int l, int r) {
    if (l > r) return 0;
    int k = lg[r - l + 1];
    //printf("$ (%d,%d)%d (%d,%d)%d\n", l,k,mx[l][k], r-(1<<k)+1,k,mx[r-(1<<k)+1][k]);
    return max(mx[l][k], mx[r-(1<<k)+1][k]);
}
int quemx2(int l, int r) {
    if (l > r) return 0;
    int k = lg[r - l + 1];
    return max(mx2[l][k], mx2[r-(1<<k)+1][k]);
}
void init() {
    for (int i = 0; i < 19; i ++) lg[1<<i] = i;
    for (int i = 1; i < N; i ++) lg[i] = max(lg[i-1], lg[i]);
    for (int i = 1; i <= 3 * n; i ++) {
        mx[i][0] = a[i];
    }
    for (int i = 1; i <= 18; i ++) {
        for (int j = 1; j <= 3 * n; j ++) {
            if (j + (1<<i) <= 3 * n + 1)
            mx[j][i] = max(mx[j][i-1], mx[j + (1<<(i-1))][i-1]);
        }
    }


    for (int i = 1; i <= 3 * n; i ++) {
        if (quemx(1, i-1) <= 2 * a[i]) pre[i] = 0;
        else {
            int lef = 1, rig = i;
            while (rig - lef > 1) {
                int mid = (lef + rig) >> 1;
                if (quemx(mid, i) > 2 * a[i]) lef = mid;
                else rig = mid;
            }
            pre[i] = lef;
        }
    }

    for (int i = 1; i <= 3 * n; i ++) {
        mx2[i][0] = pre[i];
    }
    for (int i = 1; i <= 18; i ++) {
        for (int j = 1; j <= 3 * n; j ++) {
            if (j + (1<<i) <= 3 * n + 1)
                mx2[j][i] = max(mx2[j][i-1], mx2[j + (1<<(i-1))][i-1]);
        }
    }
}


void solve() {
    /*
    for (int i = 1; i <= 3 * n; i ++) {
        printf("%d ", pre[i]);
    } printf("\n");
    */
    for (int i = 1; i <= n; i ++) {
        if (quemx2(i, 3 * n) < i) printf("-1 ");
        else {
            int lef = i, rig = 3 * n + 1;
            while(rig - lef > 1) {
                int mid = (lef + rig) >> 1;
                //printf("%d %d = %d\n", i, mid, quemx2(i, mid));
                if (quemx2(i, mid) < i) lef = mid;
                else rig = mid;
            }
            printf("%d ", lef - i + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        a[n+i] = a[i]; a[n+n+i] = a[i];
    }
    init();
    solve();
}