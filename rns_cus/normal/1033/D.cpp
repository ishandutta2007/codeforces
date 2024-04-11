#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 555

int n, d[2];
ll a[N];
const int mod = 998244353;

map <ll, int> mp, vis;

ll Sqrt(ll a) {
    ll x = sqrt(a);
    assert(x * x <= a);
    if (x * x < a) x ++;
    return x;
}

ll Cbrt(ll a) {
    ll x = cbrt(a);
    assert(x * x * x <= a);
    if (x * x * x < a) x ++;
    return x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i ++) {
        ll x = 1;
        x = Sqrt(a[i]);
        if (x * x == a[i]) {
            ll y = Sqrt(x);
            if (y * y == x)  mp[y] += 4;
            else mp[x] += 2;
            continue;
        }
        x = Cbrt(a[i]);
        if (x * x * x == a[i]) {mp[x] += 3; continue;}
        x = 1;
        for (int j = 0; j < n; j ++) {
            if (a[i] != a[j]) {
                x = __gcd(a[i], a[j]);
                if (x == a[i]) {
                    assert(0);
                }
                if (x > 1) break;
            }
        }
        if (x > 1) mp[x] ++, mp[a[i]/x] ++;
        else vis[a[i]] ++;
    }
    int rlt = 1;
    for (map <ll, int> :: iterator it = mp.begin(); it != mp.end(); it ++) rlt = 1ll * rlt * (it -> second + 1) % mod;
    for (map <ll, int> :: iterator it = vis.begin(); it != vis.end(); it ++) rlt = 1ll * rlt * (it -> second + 1) % mod * (it -> second + 1) % mod;
    printf("%d\n", rlt);
    fflush(stdout);

    return 0;
}