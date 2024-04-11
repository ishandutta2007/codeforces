#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3e5 + 3;

const int B = 550;

vector <int> es[N];
bool u[N];
ll d[N];
ll ans[N];
ll ta;
int a[N], b[N];
int n, m, w[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", w + i);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", a + i, b + i);
        if (b[i] < B)
            es[b[i]].push_back(i);
        else {
            ta = 0;
            for (int j = a[i]; j <= n; j += b[i])
                ta += w[j];
            ans[i] = ta;
        }
    }

    for (int i = 1; i <= n; i++)
        d[i] = w[i];

    for (int r = B - 1; r > 0; r--) {
        for (int i = n - r; i > 0; i--)
            d[i] = d[i + r] + w[i];
        for (int p: es[r])
            ans[p] = d[a[p]];
    }

    for (int i = 0; i < m; i++)
        printf("%I64d\n", ans[i]);

    return 0;
}