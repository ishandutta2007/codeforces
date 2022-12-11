#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ld eps = 1e-11;

ll n, k;
ll a[N];
ll sum;
ll tmp;

vector <ll> s, b;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
        sum += a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] * n < sum)
            s.push_back(a[i]);
        if (a[i] * n > sum)
            b.push_back(a[i]);
    }

    ll l, r, m;
    l = 0;
    r = 2e10 + 3;

    //cerr << r << "\n";

    while (r - l > 1) {
        m = (l + r) / 2;
        tmp = 0;
        for (int i = 0; i < s.size(); i++) {
            tmp += max(0ll, m - s[i]);
        }
        if (tmp <= k)
            l = m;
        else
            r = m;
    }
    ll ss = l;

    l = -1e10 - 1;
    r = 1e10 + 1;

    while (r - l > 1) {
        m = (l + r) / 2;
        tmp = 0;
        for (int i = 0; i < b.size(); i++) {
            tmp += max(0ll, b[i] - m);
        }
        if (tmp <= k)
            r = m;
        else
            l = m;
    }
    ll bb = r;

    if (bb <= ss) {
        if (sum % n == 0)
            printf("0\n");
        else
            printf("1\n");
    } else {
        printf("%I64d\n", bb - ss);
    }


    return 0;
}