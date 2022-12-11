#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 5e5 + 7;
///const ll L = 3000;
const ll L = 1250;
const ll B = 400;
const ll inf = 1e18;


struct Block {
    ll add;
    pair <ll, ll> a[L];
};

Block a[B];
ll n, m, t, x, l, r, M, big, smal;
pair <ll, ll> b[L + 1], c[L + 1];
ll lb, lc, ub, uc, ua;
bool u[L];

bool is_in(ll num, ll x) {
    x -= a[num].add;
    if (x > a[num].a[L - 1].first)
        return false;
    return (a[num].a[lower_bound(a[num].a, a[num].a + L, make_pair(x, -1ll)) - a[num].a].first == x);
}

void msort(ll num) {
    lb = lc = ub = uc = ua = 0;
    for (int i = 0; i < L; i++)
        if (u[i]) b[lb++] = a[num].a[i];
        else c[lc++] = a[num].a[i];
    while (ub < lb || uc < lc) {
        if (uc < lc && (ub == lb || c[uc] < b[ub]))
            a[num].a[ua++] = c[uc++];
        else
            a[num].a[ua++] = b[ub++];
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d", &n, &m);
    for (int i = 0; i < L * B; i++) {
        if (i < n)
            scanf("%I64d", &x);
        else
            x = inf;
        a[i / L].a[i % L] = make_pair(x, i);
        a[i / L].add = 0;
    }

    for (int i = 0; i < B; i++)
        sort(a[i].a, a[i].a + L);

    while (m--) {
        scanf("%I64d", &t);
        if (t == 2) {
            scanf("%I64d", &x);
            l = r = -1;
            for (int i = 0; i < B; i++)
                if (is_in(i, x)) {
                    if (l == -1)
                        l = i;
                    r = i;
                }

            if (l == -1) {
                printf("-1\n");
                continue;
            }

            smal = L * B;
            big = -1;
            for (int i = 0; i < L; i++) {
                if (a[l].a[i].first + a[l].add == x)
                    smal = min(smal, a[l].a[i].second);
                if (a[r].a[i].first + a[r].add == x)
                    big = max(big, a[r].a[i].second);
            }

            if (big < smal) {
                printf("%I64d_%I64d_%I64d_%I64d__%I64d", l, r, big, smal, x);
                continue;
            }

            printf("%I64d\n", big - smal);
        } else {
            scanf("%I64d%I64d%I64d", &l, &r, &x);
            l--;
            r--;
            if (l / L == r / L) {
                for (int i = 0; i < L; i++)
                    if (l <= a[r / L].a[i].second && a[r / L].a[i].second <= r) {
                        a[r / L].a[i].first += x;
                        u[i] = true;
                    } else
                        u[i] = false;
                msort(r / L);
            } else {
                for (int i = 0; i < L; i++)
                    if (l <= a[l / L].a[i].second) {
                        a[l / L].a[i].first += x;
                        u[i] = true;
                    } else
                        u[i] = false;
                msort(l / L);

                for (int i = 0; i < L; i++)
                    if (a[r / L].a[i].second <= r) {
                        a[r / L].a[i].first += x;
                        u[i] = true;
                    } else
                        u[i] = false;
                msort(r / L);

            }

            for (int i = l / L + 1; i < r / L; i++)
                a[i].add += x;

        }
    }

    return 0;
}