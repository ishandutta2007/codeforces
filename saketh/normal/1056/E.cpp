#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename H, int B, typename V> struct rabin_karp {
    array<H, B> bases;
    vector<H> pows;

    rabin_karp(int maxv) {
        for (int i = 0; i < B; i++)
            bases[i] = H(maxv + rng() % maxv);
        pows.resize(B, H(1));
    }
    H pow(int i, int e) {
        while (pows.size() <= B * e + i)
            pows.push_back(pows[pows.size() - B] * bases[pows.size() % B]);
        return pows[B * e + i];
    }

    struct polyhash {
        rabin_karp<H, B, V>& rk;
        vector<H> pref;

        polyhash(const vector<V>& e, auto& _rk) : rk(_rk) {
            pref.resize(B * (e.size() + 1));
            for (int i = 0; i < pref.size(); i++)
                if (i < B) pref[i] = H(0);
                else pref[i] = pref[i - B] * rk.bases[i % B] + H(e[i/B - 1]);
        }

        array<H, B> operator () (int i, int j) const {
            array<H, B> res;
            for (int b = 0; b < B; b++)
                res[b] = pref[j * B + b] - rk.pow(b, j - i) * pref[i * B + b];
            return res;
        }
    };
    polyhash hash(const vector<V>& e) { return polyhash(e, *this); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MOD = 1e9 + 7;
    rabin_karp<modnum<MOD>, 1, char> rk(CHAR_MAX);

    string s, t;
    cin >> s >> t;

    vector<char> tvec(all(t));
    auto thash = rk.hash(tvec);
    using MM = array<modnum<MOD>, 1>;

    int zc = 0, oc = 0;
    for (char c : s) {
        if (c == '0') zc++;
        else oc++;
    }

    int M = t.size();
    bool big = oc > zc;
    int ans = 0;

    for (int bl = 1; bl <= M; bl++) {
        int rem = M - max(zc, oc) * bl;
        if (rem <= 0) break;
        if (rem % min(zc, oc) != 0) continue;
        int sl = rem / min(zc, oc);

        int fb = -1, fs = -1, inx = 0;
        MM bh, sh;
        bool good = true;

        for (char c : s) {
            if (c - '0' == big) {
                if (fb == -1) {
                    fb = inx;
                    bh = thash(inx, inx + bl);
                }
                else {
                    if (thash(inx, inx + bl) != bh) {
                        good = false;
                        break;
                    }
                }
                inx += bl;
            } else {
                if (fs == -1) {
                    fs = inx;
                    sh = thash(inx, inx + sl);
                } else {
                    if (thash(inx, inx + sl) != sh) {
                        good = false;
                        break;
                    }
                }
                inx += sl;
            }
        }

        if (good && (bh != sh)) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}