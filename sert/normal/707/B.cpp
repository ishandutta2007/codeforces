#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const int INF = 1e9 + 34;

int ans = INF, n, m, k, x;
bool u[N];
int v1[N], v2[N], l[N];

int main() {
    //init();

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", v1 + i, v2 + i, l + i);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        u[x] = true;
    }

    for (int i = 0; i < m; i++) {
        if (u[v1[i]] != u[v2[i]])
            ans = min(ans, l[i]);
    }

    printf("%d", (ans == INF ? -1 : ans));

    return 0;
}