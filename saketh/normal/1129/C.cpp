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
const int MOD = 1e9 + 7;
using mn = modnum<MOD>;

namespace aho {
    const int SIGMA = 2;
    const int TOTL = 1e7;

    struct node {
        mn msg;
        array<int, SIGMA> link;

        node() {
            msg = 1;
            fill(all(link), 0);
        }
    };

    int tail = 1;
    vector<node> trie(TOTL);

    mn add_pattern(const vi& patt) {
        mn incr = 0;

        vi trail = { 0 };
        vi vals;

        for (int c : patt) {
            vals.push_back(c);

            int &nloc = trie[trail.back()].link[c];
            if (!nloc) {
                nloc = tail++;

                trie[nloc].msg = 0;

                int T = trail.size();
                for (int s = 1; s <= 4 && s <= T; s++) {
                    if (s == 4) {
                        int last4 = 8 * vals[T - 1] + 4 * vals[T - 2] + 2 * vals[T - 3] + vals[T - 4];
                        if (last4 == 0b0011 || last4 == 0b0101 || last4 == 0b1110 || last4 == 0b1111) continue;
                    }
                    trie[nloc].msg += trie[trail[trail.size() - s]].msg;
                }
                incr += trie[nloc].msg;
            }

            trail.push_back(nloc);
        }

        return incr;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vi vals;

    mn ans = 0;
    for (int i = 0, v; i < N; i++) {
        cin >> v;
        vals.insert(vals.begin(), v);

        ans += aho::add_pattern(vals);
        cout << ans << "\n";
    }

    return 0;
}