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
const int N = (int)1e6 + 34;
const int INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;
const ll p1 = 997;
const ll p2 = 2017;

int f[N][20];
bool u[N];
int p[2000];
int len;

int main() {
    init();

    for (int r = 0; r < N; r++)
        f[r][0] = 1;
    for (int n = 1; n < 20; n++)
        f[0][n] = 2;
    for (int r = 1; r < N; r++)
    for (int n = 1; n < 20; n++) {
        f[r][n] = (f[r][n - 1] + f[r - 1][n]) % md;
    }

    for (int i = 2; i < 1000; i++) {
        if (!u[i]) {
            p[len++] = i;
            for (int j = i * i; j < N; j += i)
                u[j] = true;
        }
    }

    int q, r, x;
    int deg;
    ll ans;
    scanf("%d", &q);

    while (q--) {
        scanf("%d%d", &r, &x);
        ans = 1;
        for (int i = 0; i < len; i++) {
            if (x % p[i]) continue;
            deg = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                deg++;
            }
            ans = (ans * f[r][deg]) % md;
        }
        if (x > 1)
            ans = (ans * f[r][1]) % md;
        printf("%I64d\n", ans);
    }

    return 0;
}