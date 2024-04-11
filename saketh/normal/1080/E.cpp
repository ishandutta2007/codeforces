#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

/*
 * Given a string of length N, returns a vector "pal" of 2N-1 elements
 * For even i, pal[i] = the length of the largest palindrome centered
 *                      at index i/2 of the input string
 * For odd i,  pal[i] = the length of the largest palindrome centered
 *                      between indices i/2 and i/2+1 of the input string
 */
template<typename T> vi manacher(const vector<T>& str) {
    vi pal(max(2 * int(str.size()) - 1, 0));

    auto match = [&str, &pal](int i, int l) {
        if (i-l < -1 || i+l > pal.size()) return false;
        return (i-l)&1 || str[(i-l)/2] == str[(i+l)/2];
    };

    for (int c = 0, end = -1, ref; c < pal.size(); c++) {
        if (end > c)
            pal[c] = min(pal[2 * ref - c], end - c);
        while (match(c, pal[c] + 1))
            pal[c]++;
        if (c + pal[c] > end) {
            ref = c;
            end = c + pal[c];
        }
    }
    return pal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //vector<char> str = { 'a', 'b', 'c' };
    //WATCHC(manacher(str));

    int N, M;
    cin >> N >> M;

    vs grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    using MN = modnum<1000000007>;
    MN base = 256 + rng() % 256;
    vector<MN> pows({1});
    for (int e = 1; e < 256; e++)
        pows.push_back(pows.back() * base);

    ll ans = 0;
    vector<MN> hashes;
    auto record = [&]() {
        if (hashes.size()) {
            vi pals = manacher(hashes);
            for (int i = 0; i < pals.size(); i++) {
                if (i&1) ans += pals[i]/2;
                else ans += (pals[i] + 1)/2;
            }
        }
        hashes.clear();
    };

    for (int c1 = 0; c1 < M; c1++) {
        vvi rct(N, vi(26));
        vector<MN> rh(N);
        vi odd(N);

        for (int c2 = c1; c2 < M; c2++) {
            for (int r = 0; r < N; r++) {
                char add = grid[r][c2] - 'a';
                odd[r] -= rct[r][add]&1;
                rh[r] -= rct[r][add] * pows[add];
                rct[r][grid[r][c2] - 'a']++;
                odd[r] += rct[r][add]&1;
                rh[r] += rct[r][add] * pows[add];

                if (odd[r] <= 1) {
                    hashes.push_back(rh[r]);
                } else {
                    record();
                }
            }
            record();
        }
    }
    cout << ans << endl;

    return 0;
}