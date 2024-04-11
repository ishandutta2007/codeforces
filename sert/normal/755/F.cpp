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
#define M 500001

const int B = 200;

int p[N];
int a[N];
vector <int> d;
int odd;
bool u[N];

bitset <M> b;
bool r[N];

int main() {
    init();
    int n, x, v, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
        p[i]--;
    }

    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        v = p[i];
        x = 1;
        u[i] = true;
        while (v != i) {
            u[v] = true;
            x++;
            v = p[v];
        }
        if (x < B) a[x]++;
        else d.push_back(x);
        if (x % 2) odd++;
        //cerr << x << " ";
    }
    //cerr << "\n";
    int mx = min(n, k + min(k, (n - odd) / 2));
    int mn = k;

    if (k * 2 > n) k = n - k;

    b[0] = 1;
    for (int w: d) {
        if (w > k) continue;
        b = (b | (b << w));
    }

    for (int i = 0; i < M; i++) {
        r[i] = b[i];
    }

    int bal;
    for (int len = 2; len < B; len++) {
        if (a[len] == 0) continue;
        for (int ost = 0; ost < len; ost++) {
            bal = 0;
            for (int i = ost; i <= k; i += len) {
                if (r[i]) bal = a[len];
                else if (bal > 0) {
                    r[i] = true;
                    bal--;
                }
            }
        }
    }

    if (!r[k]) mn++;

    printf("%d %d\n", mn, mx);

    return 0;
}