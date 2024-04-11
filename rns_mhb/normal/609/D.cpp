#include <bits/stdc++.h>
using namespace std;

#define N 200005

const int INF = 1e9;
typedef long long ll;
typedef pair<ll, int> pli;
int n, m, k, s;
int a[N], b[N];
int mna[N], mnb[N];
int t[N], c[N];
ll cost[N];
pli tmp[N];

bool test(int x) {
    if (!x) return 0;
    if (x == n + 1) return 1;
    ll tot = 0;
    for (int i = 1; i <= m; i ++) {
        if (t[i] == 1) cost[i] = 1ll * a[mna[x]] * c[i];
        else cost[i] = 1ll * b[mnb[x]] * c[i];
    }
    sort(cost + 1, cost + m + 1);
    for (int i = 1; i <= k; i ++) tot += cost[i];
    return tot <= s;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for (int i = 1, mn = INF; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (mn > a[i]) {
            mn = a[i];
            mna[i] = i;
        }
        else mna[i] = mna[i-1];
    }
    for (int i = 1, mn = INF; i <= n; i ++) {
        scanf("%d", &b[i]);
        if (mn > b[i]) {
            mn = b[i];
            mnb[i] = i;
        }
        else mnb[i] = mnb[i-1];
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &t[i], &c[i]);
    }
    int st = 0, en = n + 1;
    while (st < en) {
        int mid = st + en >> 1;
        if (test(mid)) en = mid;
        else st = mid + 1;
    }
    if (st == n + 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", st);
    for (int i = 1; i <= m; i ++) {
        if (t[i] == 1) tmp[i] = pli(1ll * a[mna[st]] * c[i], i);
        else tmp[i] = pli(1ll * b[mnb[st]] * c[i], i);
    }
    sort(tmp + 1, tmp + m + 1);
    for (int i = 1; i <= k; i ++) {
        printf("%d %d\n", tmp[i].second, t[tmp[i].second] == 1 ? mna[st] : mnb[st]);
    }
    return 0;
}