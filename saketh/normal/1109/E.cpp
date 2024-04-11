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

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
    vector<T> value;
    vector<U> prop;
    vb dirty;
    bool push_down;

    seg_tree_lazy<T, U>(int _S, bool push_down = true) : push_down(push_down) {
        for (S = 1, H = 1; S < _S; S *= 2, H++);
        value.resize(2*S), dirty.resize(2*S), prop.resize(2*S);
    }

    void rebuild() {
        for (int i = S - 1; i > 0; i--)
            value[i] = prop[i](value[2 * i] + value[2 * i + 1]);
    }

    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            value[l] = prop[l](value[2*l] + value[2*l+1]);
        }
    }

    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if (i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }

    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
                prop[l] = U();
                dirty[l] = false;
            }
        }
    }

    void upd(int i, int j, U update) {
        i += S, j += S;
        if (push_down) propagate(i), propagate(j);

        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if ((l&1) == 1) apply(l++, update);
            if ((r&1) == 0) apply(r--, update);
        }
        rebuild(i), rebuild(j);
    }

    T query(int i, int j) {
        i += S, j += S;
        if (push_down) propagate(i), propagate(j);

        T res_left, res_right;
        for (; i <= j; i /= 2, j /= 2) {
            if ((i&1) == 1) res_left = res_left + value[i++];
            if ((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

int MOD, TOT;
struct modnum {
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
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }

    modnum& operator *= (const modnum& o) {
        uint64_t x = uint64_t(v) * o.v;
        unsigned x_high = x >> 32, x_low = (unsigned) x, quot;
        asm("divl %4\n"
                : "=a" (quot), "=d" (v)
                : "d" (x_high), "a" (x_low), "r" (MOD));
        return *this;
    }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(int e) const {
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        int g = MOD, x = 0, y = 1;
        for (int r = v; r != 0; ) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};
using mn = modnum;

const int MAXP = 9;
const int MAXQ = 1e5;
const int MAXV = 1e5;
constexpr int MAXE = MAXQ * ceil(log(MAXV) / log(2)) + 1;

vi primes;
mn ppow[MAXP][MAXE];

void init() {
    TOT = 1;
    int tmp = MOD;
    for (int p = 2; p <= min(MOD, MAXV); p++) {
        if (tmp % p) continue;
        primes.push_back(p);
        TOT *= p - 1;
        tmp /= p;
        while (tmp % p == 0) {
            tmp /= p;
            TOT *= p;
        }
    }
    if (tmp > 1) TOT *= tmp - 1;
    for (int i = 0; i < primes.size(); i++) {
        ppow[i][0] = 1;
        for (int e = 1; e < MAXE; e++)
            ppow[i][e] = ppow[i][e-1] * primes[i];
    }
}

tuple<mn, array<int, MAXP>> decomp(int uval, bool invert) {
    array<int, MAXP> pows;
    fill(all(pows), 0);

    for (int i = 0; i < primes.size(); i++) {
        while (uval % primes[i] == 0) {
            pows[i]++;
            uval /= primes[i];
        }
    }

    mn val = mn(uval);

    if (invert) {
        val = 1 / val;
        for (auto& e : pows)
            e *= -1;
    }

    return { val, pows };
}

struct node {
    mn val;
    array<int, MAXP> pows;

    node(mn val = 0) : val(val) {
        fill(all(pows), 0);
    }

    node(const tuple<mn, array<int, MAXP>> args) {
        tie(val, pows) = args;
    }

    mn eval() const {
        mn res = val;
        for (int i = 0; i < primes.size(); i++)
            res *= ppow[i][pows[i]];
        return res;
    }

    node operator+ (const node &o) const {
        return node(eval() + o.eval());
    }
};

struct update {
    mn val;
    array<int, MAXP> pows;

    update(int uval = 1, bool invert = false) {
        tie(val, pows) = decomp(uval, invert);
    }

    update operator+ (const update& o) const {
        update res;
        res.val = val * o.val;
        for (int i = 0; i < primes.size(); i++)
            res.pows[i] = pows[i] + o.pows[i];
        return res;
    }

    node operator() (const node &n) const {
        node res = n;
        res.val = n.val * val;
        for (int i = 0; i < primes.size(); i++)
            res.pows[i] += pows[i];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N >> MOD;
    init();

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int Q;
    cin >> Q;

    vector<array<int, 4>> ops(Q);
    for (int q = 0; q < Q; q++) {
        int op, l, r, x, p;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            ops[q] = { 1, l, r, x };
        } else if (op == 2) {
            cin >> p >> x;
            ops[q] = { 2, p, p, x };
        } else {
            cin >> l >> r;
            ops[q] = { 3, l, r };
        }
    }

    seg_tree_lazy<node, update> st(N, true);
    for (int i = 0; i < N; i++) {
        st.value[st.S + i] = node(decomp(a[i], false));
    }
    st.rebuild();

    for (int q = 0; q < Q; q++) {
        if (ops[q][0] == 1) {
            st.upd(ops[q][1] - 1, ops[q][2] - 1, update(ops[q][3]));
        } else if (ops[q][0] == 2) {
            st.upd(ops[q][1] - 1, ops[q][2] - 1, update(ops[q][3], true));
        } else {
            cout << st.query(ops[q][1] - 1, ops[q][2] - 1).eval() << "\n";
        }
    }

    return 0;
}