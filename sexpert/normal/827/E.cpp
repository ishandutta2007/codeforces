#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
            auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

const int MAXN = 5e5 + 10;
vector<int> primes[MAXN];

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> per(n + 1, 1);
    per[0] = 0;

    vector<double> a(n), b(n);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'V')
            a[i] = 1;
        if(s[i] == 'K')
            b[n - 1 - i] = 1;
    }

    auto c = conv(a, b);
    for(int i = 0; i < c.size(); i++) {
        int x = abs(i - (n - 1));
        if(round(c[i]))
            per[x] = 0;
    }

    for(int i = n; i >= 1; i--) {
        if(per[i])
            continue;
        for(auto q : primes[i])
            per[i / q] = 0;
    }

    cout << accumulate(per.begin(), per.end(), 0) << '\n';
    for(int i = 1; i <= n; i++)
        if(per[i]) cout << i << " ";

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAXN; p++) {
        if(primes[p].size())
            continue;
        for(int q = p; q < MAXN; q += p)
            primes[q].push_back(p);
    }

    int t;
    cin >> t;
    while(t--)
        solve();
}