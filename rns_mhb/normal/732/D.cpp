#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf -1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, m, s, d[N], a[N], cur[N];
bool vis[N];

bool check(int k) {
    memset(cur, 0, sizeof cur);
    int i, s = 0;
    for (i = 1; i <= k; i ++) cur[d[i]] = i;
    for (i = 1; i <= m; i ++)
        if (!cur[i]) return 0;
    for (i = 1; i <= m; i ++) vis[cur[i]] = 1;
    for (i = 1; i <= k; i ++) {
        if (vis[i]) s -= a[d[i]];
        else s ++;
        if (s < 0) break;
    }
    for (i = 1; i <= m; i ++) vis[cur[i]] = 0;
    return s >= 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &d[i]);
    for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
    int l = 1, r = n + 1, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l > n) puts("-1");
    else printf("%d\n", l);

    return 0;
}