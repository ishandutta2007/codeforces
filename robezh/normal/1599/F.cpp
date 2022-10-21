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
const int N = (int)2e5 + 50;

inline ll mul(ll a, ll b, ll M) {
    ll b0 = (b >> 16);
    return (((a * b0 % M) << 16) + a * (b - (b0 << 16))) % M;
}


ll fp(ll x, ll k, ll M) {
    if(k == 0) return 1;
    ll pw = x;
    ll res = 1;
    while(k > 1) {
        if(k & 1) res = mul(res, pw, M);
        pw = mul(pw, pw, M);
        k >>= 1;
    }
    if(k & 1) res = mul(res, pw, M);
    return res;
//    return k % 2 == 1 ? mul(mul(hf, hf, M), x, M) : mul(hf, hf, M);
}

const int mod = (int)1e9 + 7;

const ll M = 44000000309;
/*
44000000309
96000000673
104000000729
116000000813
*/

int n;


struct BIT {
    ll M;
    ll bit[N];

    void add(int x, ll val) {
        for(int i = x; i < n; i |= i + 1) (bit[i] += val) %= M;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  (res += bit[i]) %= M;
        return res;
    }
} bit[3];

int q;
ll B;
int a[N];

struct Qr {
    int r, d, idx;
};

vector<Qr> qr[N];

ll get_seq(ll x, ll k) {
    ll p = fp(B, x, M);
    assert(p != 1);
    return mul(fp(p, k, M) - 1, fp(p - 1, M - 2, M), M);
}

int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bit[0].M = M;
    bit[1].M = mod;
    bit[2].M = mod;

    B = fp(2, 44, M);
    assert((fp(B, mod, M) % M == 1));
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, q) {
        int l, r, d; cin >> l >> r >> d; l--, r--;
        qr[l].push_back({r, d, i});
    }
    unordered_map<int, int> las;

    for (int i = n - 1; i >= 0; i--) {
        auto it = las.find(a[i]);
        if(it != las.end()) {
            bit[0].add(it -> second, M - fp(B, a[i], M));
            bit[1].add(it -> second, mod - a[i]);
            bit[2].add(it -> second, mod - 1);
        }
        bit[0].add(i, fp(B, a[i], M));
        bit[1].add(i, a[i]);
        bit[2].add(i, 1);
        for (auto qi : qr[i]) {
            if(qi.d == 0) res[qi.idx] = (bit[2].get(qi.r) - 1) % mod == 0;
            else {
                ll len = bit[2].get(qi.r);
                ll fir = (bit[1].get(qi.r) - 1LL * qi.d * (1LL * len * (len - 1) / 2 % mod)) % mod * fp(len, mod - 2, mod) % mod;
                if(fir < 0) fir += mod;
                ll sum = mul(fp(B, fir, M), get_seq(qi.d, len), M);
                res[qi.idx] = (sum - bit[0].get(qi.r)) % M == 0;
            }
        }
        las[a[i]] = i;
    }
    rep(i, 0, q) cout << (res[i] ? "Yes" : "No") << '\n';


}