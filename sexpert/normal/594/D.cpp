#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int BS = 450;
const int MAXN = 2e5 + 10;
const int MAX = 1000*1000 + 5;
ll inv[MAX], phier[MAX], aphier[MAX], ans[MAX], pp[MAX], BIT[MAXN];
int prime[MAX], a[MAX], prv[MAX], n;
vector<pair<int, int>> qs[MAXN];
vector<int> primes, pf[MAX];

ll _inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

void upd(int p, ll v) {
    if(p == 0)
        return;
    for(; p < MAXN; p += (p & -p)) {
        BIT[p] = (BIT[p] * v) % MOD;
    }
}

ll qry(ll p) {
    ll res = 1;
    for(; p; p -= (p & -p))
        res = (res * BIT[p]) % MOD;
    return res;
}

void sieve() {
    for(int p = 2; p < MAX; p++) {
        if(prime[p])
            continue;
        for(int q = p; q < MAX; q += p) {
            prime[q] = p;
            pf[q].push_back(p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i < MAX; i++)
        inv[i] = _inv(i);
    sieve();
    for(int i = 1; i < MAX; i++) {
        phier[i] = (inv[i] * (i - 1)) % MOD;
        aphier[i] = (inv[i - 1] * i) % MOD;
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    pp[0] = 1;
    for(int i = 1; i <= n; i++)
        pp[i] = (pp[i - 1] * a[i]) % MOD;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qs[r].push_back({l, i});
    }
    fill(BIT, BIT + MAXN, 1);
    for(int r = 1; r <= n; r++) {
        for(auto p : pf[a[r]]) {
            upd(prv[p], aphier[p]);
            prv[p] = r;
            upd(r, phier[p]);
        }
        for(auto q : qs[r]) {
            ll res = (pp[r] * _inv(pp[q.first - 1])) % MOD;
            res = (res * qry(r)) % MOD;
            res = (res * _inv(qry(q.first - 1))) % MOD;
            ans[q.second] = res;
        }
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}