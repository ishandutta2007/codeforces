#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll md = 1000000007;

using namespace std;

ll n, k, a[N], l[N];
ll c[N], z[N];
ll lc, lz;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    if (k == 0){
        cout << 0;
        return 0;
    }

    fr(i, k) cin >> a[i];
    sort(a, a + k);

    l[0] = a[0] - 1;
    l[k] = n - a[k - 1];

    for(int i = 1; i < k; i++)
        l[i] = a[i] - a[i - 1] - 1;

    for(int j = 0; j <= k; j++)
        for(int i = 2; i <= l[j]; i++)
            z[i]++;

    for(int i = 2; i <= n - k; i++)
        c[i]++;

    for(int i = 1; i < k; i++)
        if (l[i] != 0)
            c[2] += l[i] - 1;

    for(int i = 1100; i >= 2; i--)
        for(int j = 2; j < i; j++)
            if (i % j == 0){
                c[j] += c[i];
                c[i / j] += c[i];
                c[i] = 0;
                z[j] += z[i];
                z[i / j] += z[i];
                z[i] = 0;
                break;
            }

    ll ans = 1;
    for(int i = 1; i <= 1100; i++)
        for(int j = 0; j < c[i] - z[i]; j++)
            ans = (ans * i) % md;

    cout << ans;

    return 0;
}