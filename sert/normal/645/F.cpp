#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;
int x, cst[N];
bool fnd;
ll c[N];
ll ans = 0;
int n, k, q;
ll a[N];

ll ob = 919390594;
vector <ll> o;
vector <ll> f;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    /*ll e = 1;
    for (int i = 1; i < N; i++)
        e = (e * i) % md;
    for (ll i = 1; true; i++) {
        if ((e * i) % md == 1) {
            cout << i;
            return 0;
        }
    }*/

    for (int i = N - 1; i >= 2; i--) {
        ob = (ob * i) % md;
        o.push_back(ob);
    }
    o.push_back(1);
    reverse(o.begin(), o.end());
    f.push_back(1);
    f.push_back(1);
    for (int i = 2; i < N; i++)
        f.push_back((f.back() * i) % md);

    cst[1] = 1;
    for (int i = 2; i < N; i++) {
        x = i;
        fnd = false;
        cst[i] = i;
        for (int j = 1; j * j <= x; j++) {
            if (x % j) continue;
            cst[i] -= cst[j];
            if (j * j < x && j > 1)
                cst[i] -= cst[x / j];
        }
    }

    scanf("%d%d%d", &n, &k, &q);
    c[k] = 1;
    for (ll i = k + 1; i < N; i++)
        c[i] = (((c[i - 1] * i) % md) * ((o[i - k] * f[i - k - 1]) % md)) % md;

    for (int i = 0; i < n + q; i++) {
        scanf("%d", &x);
        for (int j = 1; j * j <= x; j++) {
            if (x % j) continue;
            a[j]++;
            ans = (ans + (c[a[j]] - c[a[j] - 1]) * cst[j] + md * md * 2) % md;
            if (j * j < x) {
                a[x / j]++;
                ans = (ans + (c[a[x / j]] - c[a[x / j] - 1]) * cst[x / j] + md * md * 2) % md;
            }
        }
        if (i >= n)
            printf("%I64d\n", ans);
    }

    return 0;
}