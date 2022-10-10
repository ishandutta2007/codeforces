#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
ll pr[MAXN], f[MAXN], g[MAXN], s[MAXN], ss[MAXN], sss[MAXN];

ll bruh(ll n) {
    ll res = 1;
    while(n > 1) {
        ll p = pr[n], a = 0, pa = 1;
        while(n % p == 0) {
            n /= p;
            a++;
            pa *= p;
        }
        ll tm = ((a + 1) * pa - a * (pa/p));
        res *= tm;
    }
    return res;
}

void add(ll &x, ll y) {
    y %= MOD;
    x += y;
    x %= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAXN; p++) {
        if(pr[p])
            continue;
        for(int q = p; q < MAXN; q += p)
            pr[q] = p;
    }

    for(int i = 1; i < MAXN; i++)
        f[i] = bruh(i);

    for(ll i = 1; i < MAXN; i++) {
        g[i] = (i*(i + 1)*(2*i + 1)/3 - i*i*3 + 2LL*f[i]) % MOD;
        s[i] = (s[i - 1] + g[i]) % MOD;
        ss[i] = (ss[i - 1] + i*g[i]) % MOD;
        sss[i] = (sss[i - 1] + ((i * g[i])%MOD * i)) % MOD;
    }

    //for(int i = 1; i <= 10; i++)
    //    cout << g[i] << " " << s[i] << " " << ss[i] << " " << sss[i] << '\n';

    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        ll k = min(n, m);
        add(ans, sss[k]);
        add(ans, -(n + m + 2) * ss[k]);
        add(ans, (((n + 1)*(m + 1) % MOD) * s[k]) % MOD);
        /*for(ll s = 1; s <= min(n, m); s++) {
            ll C = (n - s + 1) * (m - s + 1);
            C %= MOD;
            ll oth = s*s*s - 4*s*s;
            oth %= MOD;
            oth += 4LL * f[s];
            oth %= MOD;
            ans = (ans + C * oth) % MOD;
        }*/
        cout << (ans + MOD) % MOD << '\n';
    }
}