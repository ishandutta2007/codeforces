#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const ll md = 1e9 + 7;

ll n, l, k, lst = -1, cur = 0;
pair <ll, ll> a[N];
ll b[N], kol[N];
vector <ll> c[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d%I64d", &n, &l, &k);
    ll len = l / n;
    ll ost = l % n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i].first != lst) {
            lst = a[i].first;
            cur++;
        }
        kol[cur]++;
        a[i].first = cur;
        swap(a[i].first, a[i].second);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        b[i] = a[i].second;

    for (int i = 0; i <= cur; i++) {
        for (int j = 0; j <= k; j++)
            c[i].push_back(0);
    }

    for (int i = 1; i <= cur; i++)
        c[i][1] = (c[i - 1][1] + kol[i]) % md;

    ll ans = (n * len) % md;

    for (int j = 2; j <= min(k, len); j++) {
        for (int i = 1; i <= cur; i++)
            c[i][j] = (c[i - 1][j] + c[i][j - 1] * kol[i]) % md;
        ans = (ans + c[cur][j] * (len % md - j + 1 + md)) % md;
    }

    ans = (ans + ost) % md;

    for (int i = 0; i < ost; i++)
        for (int j = 1; j <= min(k - 1, len); j++) {
            ans = (ans + c[b[i]][j]) % md;
        }

    printf("%I64d\n", ans);

    return 0;
}