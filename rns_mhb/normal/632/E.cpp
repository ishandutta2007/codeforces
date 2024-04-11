#include <bits/stdc++.h>
using namespace std;
#define N 1001
#define MAXN 1001000
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, k, x[N], d[MAXN];
bool vis[MAXN];
queue <int> q;

int main() {
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", &x[i]);
    sort(x, x + n);
    for (int i = 1; i < n; i ++) x[i] -= x[0];
    q.push(0), vis[0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (d[u] == k) continue;
        for (int i = 1; i < n; i ++) {
            int v = u + x[i];
            if (vis[v]) continue;
            d[v] = d[u] + 1;
            vis[v] = 1, q.push(v);
        }
    }
    for (int i = 0; i < MAXN; i ++)
        if (vis[i]) printf("%d ", i + x[0] * k);

    return 0;
}