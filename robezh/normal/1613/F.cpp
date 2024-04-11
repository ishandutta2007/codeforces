#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 250050;

namespace fft {

// NTT
    const int mod = 998244353, g = 3;
// For p < 2^30 there is also (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). Last two are > 10^9.
    struct num { /// start-hash
        int v;
        num(ll v_ = 0) : v(int(v_ % mod)) { if (v<0) v+=mod; }
        explicit operator int() const { return v; }
    };
    inline num operator+(num a,num b){return num(a.v+b.v);}
    inline num operator-(num a,num b){return num(a.v+mod-b.v);}
    inline num operator*(num a,num b){return num(1ll*a.v*b.v);}
    inline num pow(num a, int b) {
        num r = 1;
        do{if(b&1)r=r*a;a=a*a;}while(b>>=1);
        return r;
    }
    inline num inv(num a) { return pow(a, mod-2); }


    using vn = vector<num>;
    vi rev({0, 1});
    vn rt(2, num(1)), fa, fb;

    inline void init(int n) { /// start-hash
        if (n <= sz(rt)) return;
        rev.resize(n);
        rep(i,0,n) rev[i] = (rev[i>>1] | ((i&1)*n)) >> 1;
        rt.reserve(n);
        for (int k = sz(rt); k < n; k *= 2) {
            rt.resize(2*k);
            num z = pow(num(g), (mod-1)/(2*k)); // NTT
            rep(i,k/2,k) rt[2*i] = rt[i], rt[2*i+1] = rt[i]*z;
        }
    } /// end-hash

    inline void fft(vector<num> &a, int n) { /// start-hash
        init(n);
        int s = __builtin_ctz(sz(rev)/n);
        rep(i,0,n) if (i < rev[i]>>s) swap(a[i], a[rev[i]>>s]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
                    num t = rt[j+k] * a[i+j+k];
                    a[i+j+k] = a[i+j] - t;
                    a[i+j] = a[i+j] + t;
                }
    } /// end-hash

// Complex/NTT
    vn multiply(vn a, vn b) { /// start-hash
        int s = sz(a) + sz(b) - 1;
        if (s <= 0) return {};
        int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
        a.resize(n), b.resize(n);
        fft(a, n);
        fft(b, n);
        num d = inv(num(n));
        rep(i,0,n) a[i] = a[i] * b[i] * d;
        reverse(a.begin()+1, a.end());
        fft(a, n);
        a.resize(s);
        return a;
    } /// end-hash

// Complex/NTT power-series inverse
// Doubles b as b[:n] = (2 - a[:n] * b[:n/2]) * b[:n/2]
    vn inverse(const vn& a) { /// start-hash
        if (a.empty()) return {};
        vn b({inv(a[0])});
        b.reserve(2*a.size());
        while (sz(b) < sz(a)) {
            int n = 2*sz(b);
            b.resize(2*n, 0);
            if (sz(fa) < 2*n) fa.resize(2*n);
            fill(fa.begin(), fa.begin()+2*n, 0);
            copy(a.begin(), a.begin()+min(n,sz(a)), fa.begin());
            fft(b, 2*n);
            fft(fa, 2*n);
            num d = inv(num(2*n));
            rep(i, 0, 2*n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
            reverse(b.begin()+1, b.end());
            fft(b, 2*n);
            b.resize(n);
        }
        b.resize(a.size());
        return b;
    } /// end-hash
} // namespace fft

// For multiply_mod, use num = modnum, poly = vector<num>
using fft::num;
using poly = fft::vn;
using fft::multiply;
using fft::inverse;
/// start-hash
poly& operator+=(poly& a, const poly& b) {
    if (sz(a) < sz(b)) a.resize(b.size());
    rep(i,0,sz(b)) a[i]=a[i]+b[i];
    return a;
}
poly operator+(const poly& a, const poly& b) { poly r=a; r+=b; return r; }
poly& operator-=(poly& a, const poly& b) {
    if (sz(a) < sz(b)) a.resize(b.size());
    rep(i,0,sz(b)) a[i]=a[i]-b[i];
    return a;
}
poly operator-(const poly& a, const poly& b) { poly r=a; r-=b; return r; }
poly operator*(const poly& a, const poly& b) {
    // TODO: small-case?
    return multiply(a, b);
}
poly& operator*=(poly& a, const poly& b) {return a = a*b;}
/// end-hash
poly& operator*=(poly& a, const num& b) { // Optional
    trav(x, a) x = x * b;
    return a;
}
poly operator*(const poly& a, const num& b) { poly r=a; r*=b; return r; }


int n;
vi G[N];
int d[N];
num fac[N];
poly p[N];
priority_queue<pii, vector<pii>, greater<pii>> pque;

void dfs(int v, int p) {
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        d[v]++;
        dfs(nxt, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    rep(i, 0, n) {
        if(d[i]) {
            p[i] = {1, d[i]};
            pque.push({sz(p[i]), i});
        }
    }
    while(pque.size() > 1) {
        auto x = pque.top().second; pque.pop();
        auto y = pque.top().second; pque.pop();
        p[x] = p[x] * p[y];
        pque.push({sz(p[x]), x});
    }
    poly &f = p[pque.top().second];
//    for (int i=  0; i < sz(f); i++) {
//        cout << int(f[i]) << " ";
//    }
//    cout << endl;

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    num c = 1;
    num res = 0;
    rep(i, 0, min(n, sz(f))) {
        res = res + c * f[i] * fac[n - i];
        c = 0 - c;
//        cout << int(c) << int(f[i]) << " " << int(fac[n - i]) << endl;
    }
    cout << int(res) << endl;





}