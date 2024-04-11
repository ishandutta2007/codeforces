#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll x) {
    return 1ll * (x + 1) * x / 2 * 5  + 1ll * x * (x - 1) / 2;
}

int main() {
//    freopen("E.in", "r", stdin);
    long long n;
    cin >> n;
    n ++;
    if(n == 1) return puts("0 0");
    ll st = 0, en = 1000000000;
    while(en > st + 1) {
        ll mid = (st + en) / 2;
        if(calc(mid) >= n) en = mid;
        else st = mid;
    }
    ll r = n - calc(en - 1);
    ll x = en - 1, y = -2 * (en - 1);
    if(r <= en) {
        printf("%I64d %I64d\n", x + r - 1, y + 2ll * (r - 1));
        return 0;
    }
    r -= en;
    x += en; y += 2ll * en;
    if(r <= en - 1) {
        printf("%I64d %I64d\n", x - r + 1, y + 2ll * (r - 1));
        return 0;
    }
    r -= (en - 1);
    x -= (en - 1); y += 2ll * (en - 1);

    if(r <= en) {
        printf("%I64d %I64d\n", x - 2ll * (r - 1), y);
        return 0;
    }

    r -= en;
    x -= 2ll * en;

    if(r <= en) {
        printf("%I64d %I64d\n", x - r + 1, y - 2ll * (r - 1));
        return 0;
    }

    r -= en;
    x -= en;
    y -= 2ll * en;
    if(r <= en){
        printf("%I64d %I64d\n", x + r - 1, y - 2ll * (r - 1));
        return 0;
    }
    r -= en;
    x += en;
    y -= 2ll * en;
    printf("%I64d %I64d\n", x + 2ll * (r - 1), y);
}