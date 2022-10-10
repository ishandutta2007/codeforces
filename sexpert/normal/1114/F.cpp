#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 4e5 + 2;
const ll MOD = 1e9 + 7;
map<int, ll> fac[301];
map<int, ll> pinv;
int primes[62];
ll masks[301], arr[MAXN];
ll inver[62], phier[62];

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b*mpow(b, e - 1)) % MOD;
    ll p = mpow(b, e/2);
    return (p * p)%MOD;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

struct node {
    int l, r;
    ll prod, plazy, mask, mlazy;
    node *left, *right;

    node(int l, int r, ll *A) : l(l), r(r) {
        plazy = 1;
        mlazy = 0;
        mask = 0;
        if(l == r) {
            prod = A[l];
            for(auto pr : fac[prod])
                mask |= (1ll << pinv[pr.first]);
        }
        else {
            int mi = (l + r)/2;
            left = new node(l, mi, A);
            right = new node(mi + 1, r, A);
            merge();
        }
    }

    ll getm() {
        return mask | mlazy;
    }

    ll getp() {
        return (prod * mpow(plazy, (ll)(r - l + 1)))%MOD;
    }

    void merge() {
        prod = (left->getp() * right->getp())%MOD;
        mask = (left->getm() | right->getm());
    }

    void compm(ll l) {
        mlazy |= l;
    }

    void compp(ll l) {
        plazy = (plazy * l) % MOD;
    }

    void push() {
        left->compp(plazy);
        right->compp(plazy);
        left->compm(mlazy);
        right->compm(mlazy);
        plazy = 1;
        mlazy = 0;
    }

    void upd(int rl, int rr, ll x) {
        if(rr < l || r < rl)
            return;
        ll m = masks[x];
        if(rl <= l && r <= rr) {
            compp(x);
            compm(m);
            return;
        }
        push();
        left->upd(rl, rr, x);
        right->upd(rl, rr, x);
        merge();
    }

    ii qry(int rl, int rr) {
        if(rr < l || r < rl)
            return ii{1, 0};
        if(rl <= l && r <= rr)
            return ii{getp(), getm()};
        push();
        merge();
        ii p1 = left->qry(rl, rr), p2 = right->qry(rl, rr);
        return ii{(p1.first * p2.first) % MOD, p1.second | p2.second};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ct = 0;
    for(int m = 1; m <= 300; m++) {
        int k = m;
        for(int p = 2; p <= k; p++) {
            if(k % p)
                continue;
            if(m == p) {
                pinv[p] = ct;
                inver[ct] = inv(p);
                phier[ct] = ((p - 1ll)*inver[ct])%MOD;
                primes[ct++] = p;
                //cout << p << " ";
            }
            int e = 0;
            while(k % p == 0)
                k /= p, e++;
            fac[m][p] = e;
            masks[m] |= (1ll << pinv[p]);
        }
    }
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    node tree(1, n, arr);
    while(q--) {
        string t;
        int l, r;
        cin >> t >> l >> r;
        if(t == "TOTIENT") {
            ii pr = tree.qry(l, r);
            ll ans = pr.first, msk = pr.second;
            //cout << ans << " " << msk << endl;
            for(ll i = 0; i <= 61; i++) {
                if(msk & (1ll << i)) {
                    //cout << primes[i] << " ";
                    ans = (ans * phier[i]) % MOD;
                }
            }
            //cout << endl;
            cout << ans << endl;
        }
        if(t == "MULTIPLY") {
            int x;
            cin >> x;
            tree.upd(l, r, x);
        }
    }
}