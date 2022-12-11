#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll a[N], pr[N], sf[N], ans;
ll n, k, p, t, h, lh, rh, l, r, ql, qr;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> l >> r >> ql >> qr;
    fr(i, n)
        cin >> a[i];
    pr[0] = 0;
    fr(i, n)
        pr[i + 1] = pr[i] + a[i];
    sf[0] = 0;
    fr(i, n)
        sf[i + 1] = sf[i] + a[n - i - 1];

    ans = 10000000;
    ans *= ans;

    fr(i, n + 1) {
        lh = i;
        rh = n - i;
        k = 0;
        if (lh > rh)
            k = (lh - rh - 1) * ql;
        if (rh > lh)
            k = (rh - lh - 1) * qr;
        k += pr[lh] * l;
        k += sf[rh] * r;
        ans = min(k, ans);
    }

    cout << ans;
    return 0;
}