#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int MOD> struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(ll _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }
    friend istream& operator << (istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    /* requires prime MOD */
    modnum& operator /= (const modnum& o) { return (*this) *= o.pow(MOD - 2); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};
const int MOD = 998244353;
using mn = modnum<MOD>;

struct block {
    int W, l, r, all = 0;
    vi indiv;
    vector<mn> value, totleq;

    block(int l, int r) : l(l), r(r) {
        W = r - l + 1;
        indiv.resize(W, 0);
        value.resize(W, 0);
        totleq.resize(W + 1, 0);
    }

    void recalc() {
        fill(all(totleq), 0);
        for (int i = 0; i < W; i++)
            totleq[indiv[i]] += value[i];
        for (int i = 1; i < totleq.size(); i++)
            totleq[i] += totleq[i - 1];
    }

    void add(int x, int i, int j) {
        if (i > j) return;
        if (i == l && j == r) { all += x; return; }

        for (int inx = i; inx <= j; inx++)
            indiv[inx - l] += x;
        recalc();
    }

    void set(int i, mn val) {
        value[i - l] = val;
        recalc();
    }

    mn tot(int l) {
        int inx = l - all;
        if (inx < 0) return 0;
        if (inx >= totleq.size()) return totleq.back();
        return totleq[inx];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vi val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        --val[i];
    }

    const int bsz = sqrt(N);
    vector<block> blocks;
    for (int i = 0; i < N + 1; i += bsz) {
        blocks.emplace_back(i, min(i + bsz, N + 1) - 1);
    }
    auto upd = [&](int l, int r, int v) {
        for (auto& bl : blocks) {
            bl.add(v, max(l, bl.l), min(r, bl.r));
        }
    };

    mn res = 1;

    vi prev1(N, -1), prev2(N, -1);
    for (int i = 0, j = 0; i < N; i++) {
        if (i > blocks[j].r) j++;
        blocks[j].set(i, res);

        if (prev1[val[i]] != -1) {
            upd(prev2[val[i]] + 1, prev1[val[i]], -1);
        }
        upd(prev1[val[i]] + 1, i, 1);

        res = 0;
        for (auto& block : blocks) {
            res += block.tot(K);
        }

        prev2[val[i]] = prev1[val[i]];
        prev1[val[i]] = i;
    }

    cout << res << endl;
    return 0;
}