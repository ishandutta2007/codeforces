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

const int N = 1e3 + 34;

int a[N][N], k[N];
vector <int> v;
int ans;
int fr[N], fc[N], lr[N], lc[N], nr[N], nc[N];

int main() {
    init();

    for (int i = 0; i < N; i++)
        fr[i] = lr[i] = fc[i] = lc[i] = -1;

    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", a[i] + j);
            if (a[i][j]) {
                lr[i] = j;
                lc[j] = i;
                if (fr[i] == -1) fr[i] = j;
                if (fc[j] == -1) fc[j] = i;
                nr[i]++;
                nc[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (lr[i] == -1) continue;
        ans += (1 + lr[i] - nr[i]);
        ans += (m - fr[i] - nr[i]);
    }

    for (int j = 0; j < m; j++) {
        if (lc[j] == -1) continue;
        ans += (1 + lc[j] - nc[j]);
        ans += (n - fc[j] - nc[j]);
    }

    cout << ans;

    return 0;
}