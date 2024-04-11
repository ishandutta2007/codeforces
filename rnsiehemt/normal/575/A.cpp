#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
ll MOD;

struct mat {
    ll v[2][2];

    void print() {
        FO(i,0,2) FO(j,0,2) printf("%lld%c", v[i][j], " \n"[j+1==2]);
    }
    void init() {
        FO(i,0,2) FO(j,0,2) v[i][j] = 0;
    }

    void ident() {
        FO(i,0,2) FO(j,0,2) v[i][j] = 0;
        FO(i,0,2) v[i][i] = 1;
    }

    mat operator*(const mat &o) const {
        mat res; res.init();
        ll mod2 = MOD*MOD;
        FO(i,0,2) FO(j,0,2) {
            FO(k,0,2) {
                res.v[i][j] += v[i][k] * o.v[k][j];
                if (res.v[i][j] >= mod2) res.v[i][j] -= mod2;
            }
            res.v[i][j] %= MOD;
        }
        return res;
    }

    mat operator^(long long k) {
        mat res; res.ident();
        mat a = *this;
        while (k) {
            if (k&1) res = res*a;
            a = a*a;
            k /= 2;
        }
        return res;
    }
};

mat rt[200005];
int n;

void u(int i, mat m) {
    i += n+n;
    rt[i] = m;
    for (i /= 2; i; i /= 2) rt[i] = rt[2*i] * rt[2*i+1];
}

mat q(int l, int r) {
    mat lres, rres; lres.ident(), rres.ident();
    l += n+n; r += n+n;
    for (; l < r; l /= 2, r /= 2) {
        if (l&1) lres = lres * rt[l++];
        if (r&1) rres = rt[--r] * rres;
    }
    return lres * rres;
}

set<ll> spec;
ll k;
ll s[100005];

map<ll,ll> sval;

ll getS(ll i) {
    if (sval.count(i)) return sval[i];
    else return s[i%n];
}

void addspec(ll x) {
    spec.insert(max(1ll,min(k-1,x)));
    spec.insert(max(1ll,min(k-1,x+1)));
}

int main() {
    scanf("%lld%lld", &k, &MOD);
    if (k == 0) {
        printf("%lld\n", 0ll);
        return 0;
    } else if (k == 1) {
        printf("%lld\n", 1ll%MOD);
        return 0;
    }
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lld", s+i);
    }
    FO(i,0,n) {
        mat m;
        m.v[0][0] = s[i];
        m.v[1][0] = s[(i+n-1)%n];
        m.v[0][1] = 1;
        m.v[1][1] = 0;
        u(i, m);
        u(i+n, m);
    }
    int M; scanf("%d", &M);
    FO(i,0,M) {
        ll j, v;
        scanf("%lld %lld", &j, &v);
        addspec(j);
        sval[j] = v;
    }
    addspec(k-1);
    mat res; res.ident();
    ll cur = 1;
    while (cur <= k-1) {
        ll nxt = *spec.lower_bound(cur);
        // proc [cur,nxt)
        if (cur != nxt) {
            mat m = q(cur%n,(cur%n)+n);
            m = m ^ (nxt-cur) / n;
            cur += n * ((nxt-cur) / n);


            int st = cur%n;
            int en = nxt%n;
            if (en < st) en += n;
            m = m * q(st,en);
            cur = nxt;

            res = res * m;
        }
        // proc cur
        mat m;
        m.v[0][0] = getS(cur);
        m.v[1][0] = getS(cur-1);
        m.v[0][1] = 1;
        m.v[1][1] = 0;
        res = res*m;
        cur++;
    }
    printf("%lld\n", res.v[0][0]%MOD);
}