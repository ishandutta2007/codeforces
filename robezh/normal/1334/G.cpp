#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
#define M_PI 3.141592653589793
namespace fft {
    using dbl = ld;
    struct num { /// start-hash
        dbl x, y;
        num(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
    };
    inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }
    inline num inv(num a) { dbl n = (a.x*a.x+a.y*a.y); return num(a.x/n,-a.y/n); }


    using vn = vector<num>;
    vi rev({0, 1});
    vn rt(2, num(1)), fa, fb;

    inline void init(int n) { /// start-hash
        if (n <= sz(rt)) return;
        rev.resize(n);
        rep(i, 0, n)
        rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
        rt.reserve(n);
        for (int k = sz(rt); k < n; k *= 2) {
            rt.resize(2 * k);
            double a=M_PI/k; num z(cos(a),sin(a)); // FFT
            rep(i, k / 2, k)
            rt[2 * i] = rt[i], rt[2 * i + 1] = rt[i] * z;
        }
    } /// end-hash

    inline void fft(vector<num> &a, int n) { /// start-hash
        init(n);
        int s = __builtin_ctz(sz(rev) / n);
        rep(i, 0, n)
        if (i < rev[i] >> s) swap(a[i], a[rev[i] >> s]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k) rep(j, 0, k)
        {
            num t = rt[j + k] * a[i + j + k];
            a[i + j + k] = a[i + j] - t;
            a[i + j] = a[i + j] + t;
        }
    } /// end-hash

// Complex/NTT
    vn multiply(vn a, vn b) { /// start-hash
        int s = sz(a) + sz(b) - 1;
        if (s <= 0) return {};
        int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
        a.resize(n), b.resize(n);
        fft(a, n);
        fft(b, n);
        num d = inv(num(n));
        rep(i, 0, n)
        a[i] = a[i] * b[i] * d;
        reverse(a.begin() + 1, a.end());
        fft(a, n);
        a.resize(s);
        return a;
    } /// end-hash

}

const int N = (int)2e5 + 50;
string s, t;
int n, m;
vi sa, sb;
ld res[N];
ll psum[N];
int p[26];

ll getpow(int x, int p) {
    ll res = 1;
    while(p > 0) res *= x, p--;
    return res;
}

int main() {
    for(int i = 0; i < 26; i++) cin >> p[i], p[i]--;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    n = s.length(), m = t.length();
    ll suma = 0;
    rep(i, 0, n) {
        sa.push_back(s[i] - 'a');
        suma += sa[i] * sa[i] * p[sa[i]] * p[sa[i]];
    }
    rep(i, 0, m) sb.push_back(t[i] - 'a');
    for(int i = 0; i < m; i++) {
        psum[i] = getpow(sb[i], 4);
        if(i > 0) psum[i] += psum[i-1];
    }
    rep(i, n - 1, m) {
        res[i] += suma;
        res[i] += psum[i] - (i == n - 1 ? 0 : psum[i - n]);
    }
    fft::vn a(n), b(m);
    rep(i, 0, n) a[i] = fft::num(sa[i] + p[sa[i]]);
    rep(i, 0, m) b[i] = fft::num(getpow(sb[i], 3));
    auto c = fft::multiply(a, b);
    for(int i = n - 1; i < m; i++) {
        res[i] -= 2 * c[i].x;
    }

    rep(i, 0, n) a[i] = fft::num(sa[i] * sa[i] + p[sa[i]] * p[sa[i]] + 4 * sa[i] * p[sa[i]]);
    rep(i, 0, m) b[i] = fft::num(getpow(sb[i], 2));
    c = fft::multiply(a, b);
    for(int i = n - 1; i < m; i++) {
        res[i] += c[i].x;
    }

    rep(i, 0, n) a[i] = fft::num(sa[i] * p[sa[i]] * p[sa[i]] + p[sa[i]] * sa[i] * sa[i]);
    rep(i, 0, m) b[i] = fft::num(getpow(sb[i], 1));
    c = fft::multiply(a, b);
    for(int i = n - 1; i < m; i++) {
        res[i] -= 2 * c[i].x;
    }

    reverse(sa.begin(), sa.end());

    for(int i = n - 1; i < m; i++) {
//        ll sum = 0;
//        for(int j = i - (n - 1); j <= i; j++) {
//            sum += getpow(sa[j - (i - (n - 1))] - sb[j], 2) * getpow(p[sa[j - (i - (n - 1))]] - sb[j], 2);
//        }
        cout << ((ll)(res[i] + 0.5) == 0);
//        cout << "want: " << (ll)(res[i] + 0.5) << ", actual: " << sum << endl;
    }
    cout << '\n';



}