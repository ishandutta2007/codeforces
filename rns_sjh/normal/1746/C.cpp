#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 1e5 + 100;
int per[N], d[N], id[N], op[N];

bool cmp(int i, int j) {
    return d[i] > d[j];
}

int main() {
    int tcase, n;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) op[i] = n;
        for (int i = 1; i <= n; i ++) scanf("%d", per + i);
        for (int i = 1; i < n; i ++) {
            d[i] = per[i] - per[i + 1];
            id[i] = i;
        }
        sort(id + 1, id + n, cmp);
        int cur = n;
        for (int i = 1; i < n; i ++) {
            int pos = id[i];
            op[cur] = pos + 1;
            cur --;
        }
        for (int i = 1; i <= n; i ++) printf("%d ", op[i]);
        puts("");
    }
    return 0;
}