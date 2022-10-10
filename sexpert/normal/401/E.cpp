#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

const int MAXN = 1e5 + 5;
ll prime[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(prime[p]) continue;
        for(int j = p; j < MAXN; j += p)
            prime[j] = p;
    }
}

ll n, m, L, R, mod = 10000;

vi prod(vi &a, vi &b) {
    vi res;
    for(auto x : a)
        for(auto y : b)
            res.push_back((x * y)%mod);
    return res;
}

vi mdivs(ll x) {
    if(x == 1)
        return {1};
    ll p = prime[x];
    while(x % p == 0)
        x /= p;
    vi od = mdivs(x), pr = {1, -p};
    return prod(pr, od);
}

ll solve(ll upper) {
    if(upper == 0)
        return 0;
    ll ans = n*(m + 1) + m*(n + 1);
    if(upper == 1)
        return ans;
    for(ll x = 1; x <= n; x++) {
        if(x * x >= upper)
            break;
        ll B = sqrt(upper - x*x);
        //cout << x << " " << B << endl;
        while(B*B + x*x > upper)
            B--;
        while((B + 1)*(B + 1) + x*x <= upper)
            B++;
        B = min(B, m);
        for(auto d : mdivs(x)) {
            ll mul = 1;
            if(d < 0) {
                d = -d;
                mul = -1;
            }
            ll c = B/d;
            ll add = (c*(m + 1)  - d*((c*(c + 1))/2))%mod;
            add = add*2*mul*(n - x + 1);
            ans = (ans + add)%mod;
        }
    }
    return ans;
}

int main() {
    sieve();
    cin >> n >> m >> L >> R >> mod;
    ll res = solve(R*R) - solve(L*L - 1);
    res %= mod;
    if(res < 0)
        res += mod;
    cout << res << '\n';
}