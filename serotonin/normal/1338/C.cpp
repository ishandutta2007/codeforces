#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct triple {
    ll x, y, z;
};

ll getFirst(ll n)
{
    for(ll i=1; ; i<<=2) {
        if(n - i > 0) n -= i;
        else return n + i - 1;
    }
}

int ord[3][3] = {0, 1, 2, 2, 0, 1, 1, 2, 0};

triple fnc(ll a)
{
    triple now = {0, 0, 0};
    if(!a) return now;

    ll n = a, m = a & 3, k = 0, who = 2;
    if(!m) {
        now = fnc(a + 1);
        now.x -= 1, now.y -= 2, now.z -= 3;
        return now;
    }
    m--;
    while(n) n >>= 1, k++;
    if(k & 1) {
        now.y = 1LL<<k;
        k--;
        now.x = 1LL<<k;
        a ^= now.x;
        who = 0;
    }
    else {
        k--;
        now.y = 1LL<<k;
        a ^= now.y;
        k--;
        now.x = 1LL<<k;
        if(a & now.x) a ^= now.x;
        else who = 1;
    }
    now.z = now.y | now.x;

    triple nxt = fnc(a);
    ll ara[] = {nxt.x, nxt.y, nxt.z};
    sort(ara, ara+3, [](ll x, ll y) {return (x&3) < (y&3);});

    int r = ord[who][m];
    now.x |= ara[(0+r) % 3];
    now.y |= ara[(1+r) % 3];
    now.z |= ara[(2+r) % 3];
    return now;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);

        ll one = getFirst((n+2)/3);

        triple data = fnc(one);

        if(n%3 == 1) printf("%lld\n", data.x);
        if(n%3 == 2) printf("%lld\n", data.y);
        if(n%3 == 0) printf("%lld\n", data.z);
    }
}