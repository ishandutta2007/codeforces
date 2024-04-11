#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;

ll dist1(ll a, ll b) {
    ll ret = b - a;
    if(ret == 0) return 1ll * n * k;
    return ret;
}

ll dist2(ll a, ll b) {
    ll ret = 1ll * n * k - dist1(a, b);
    if(ret == 0) return 1ll * n * k;
    return ret;
}

int main() {
    int a, b;
    scanf("%d%d", &n, &k);
    scanf("%d%d", &a, &b);
    ll x = 1ll << 60, y = 0;
    ll st = 1 + a, L = 1ll * n * k;
    for(int i = 0; i < n; i ++) {
        ll ed = 1 + 1ll * i * k + b, d;
        d = dist1(st, ed);
        x = min(x, abs(L / __gcd(L, d)));
        y = max(y, abs(L / __gcd(L, d)));
        d = dist2(st, ed);
        x = min(x, abs(L / __gcd(L, d)));
        y = max(y, abs(L / __gcd(L, d)));
        ed = 1 + 1ll * i * k + (k - b);
        d = dist1(st, ed);
        x = min(x, abs(L / __gcd(L, d)));
        y = max(y, abs(L / __gcd(L, d)));
        d = dist2(st, ed);
        x = min(x, abs(L / __gcd(L, d)));
        y = max(y, abs(L / __gcd(L, d)));
    }
    cout << x << ' ' << y << endl;
}