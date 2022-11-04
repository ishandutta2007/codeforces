#include <bits/stdc++.h>

using namespace std;

const int NN = 300 * 300 + 100;

int B[NN], mx;
int a[NN], id[NN], pos[NN];

void add(int u) {
    u += 5;
    for(; u < mx; u += u & -u) B[u] ++;
}

int calc(int u) {
    u += 5;
    int ans = 0;
    for(; u > 0; u -= u & -u) ans +=B[u];
    return ans;
}

bool cmp(int i, int j) {
    if(a[i] == a[j]) return i < j;
    return a[i] < a[j];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T; cin >> T;
    while(T --) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n * m; i ++) {
            scanf("%d", a + i);
            id[i] = i;
        }
        mx = n * m + 10;
        memset(B, 0, sizeof (int) * (n * m + 50));
        sort(id, id + n * m, cmp);
        for(int i = 0, j; i < n * m; i = j) {
            for(j = i; j < n * m && a[id[j]] == a[id[i]]; j ++);
            for(int k = i, r; k < j; k = r) {
                r = (k / m + 1) * m;
                reverse(id + k, id + min(r, j));
            }
        }
        for(int i = 0; i < n * m; i ++) {
            pos[id[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i < n * m; i ++) {
            ans += calc(pos[i]) - calc(pos[i] / m * m - 1);
            add(pos[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}