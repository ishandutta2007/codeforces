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
const int INF = 1e9;

int a[N], t[N];
int m, n;

bool ok(int x) {
    bool u[m];
    for (int i = 0; i <= m; i++) u[i] = false;
    int c = 0;
    int k = 0;
    for (int i = x; i >= 0; i--) {
        if (a[i] == 0 && c > 0) c--;
        if (a[i] > 0 && u[a[i]] && c > 0) c--;
        if (a[i] > 0 && !u[a[i]]) {
            u[a[i]] = true;
            c += t[a[i] - 1];
            k++;
        }
    }
    return ((c || k != m) ? false : true);
}

int main() {
    init();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &t[i]);

    int l = 0;
    int r = n;
    int M;
    while (r - l > 1) {
        M = (l + r) / 2;
        if (!ok(M))
            l = M;
        else
            r = M;
    }
    printf("%d", (l + 2 > n ? -1 : l + 2));
    return 0;
}