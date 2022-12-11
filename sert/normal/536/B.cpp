#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const ll p1 = 31;
const ll p2 = 2011;
const ll md = 1e9 + 7;

ll st1[N], st2[N], len, a[N], ans, dif, n, m;
pair <ll, ll> h[N], ta;
char s[N];

ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2 == 1)
        return (a * step(a, st - 1)) % md;
    ll q = step(a, st / 2);
    return (q * q) % md;
}

pair <ll, ll> hsh(ll l, ll r) {
    ta.first = (h[r].first - h[l].first * st1[r - l] + md * md) % md;
    ta.second = (h[r].second - h[l].second * st2[r - l] + md * md) % md;
    return ta;
}

bool cmp(ll d) {
    return (hsh(0, len - d) == hsh(d, len));
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d %I64d\n", &n, &m);
    scanf("%s", s);
    len = strlen(s);
    for (int i = 1; i <= len; i++) {
        h[i].first = (h[i - 1].first * p1 + s[i - 1] - 'a' + 1) % md;
        h[i].second = (h[i - 1].second * p2 + s[i - 1] - 'a' + 1) % md;
    }
    st1[0] = st2[0] = 1;
    for (int i = 1; i <= len; i++) {
        st1[i] = (st1[i - 1] * p1) % md;
        st2[i] = (st2[i - 1] * p2) % md;
    }

    for (int i = 0; i < m; i++)
        scanf("%I64d", &a[i]);

    if (m == 0)
        ans = n;
    else
        ans = n - len;

    for (int i = 1; i < m; i++) {
        dif = a[i] - a[i - 1];
        dif = min(len, dif);
        ans -= dif;
        if (dif == len)
            continue;
        if (!cmp(dif)) {
            printf("0\n");
            return 0;
        }
    }
    //cerr << ans << " = ans\n";
    printf("%I64d\n", step(26ll, ans));

    return 0;
}