#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double T_PI = 2.0*acos(-1);
typedef complex<double> C;

C mul(const C &x, const C &y) {
    double rx = x.real(), ix = x.imag(), ry = y.real(), iy = y.imag();
    return C(rx*ry - ix*iy, rx*iy + ix*ry);
}

void fft(vector<C> &f, vector<C> &root, vector<int> &rev) {
    int n = f.size();
    for(int i = 0; i < n; i++)
        if(i < rev[i]) swap(f[i], f[rev[i]]);
    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                C z = mul(root[j + k], f[i + j + k]);
                f[i + j + k] = f[i + j] - z;
                f[i + j] = f[i + j] + z;
            }
        }
    }
}

vector<double> conv(vector<double> &A, vector<double> &B) {
    int sz = A.size() + B.size() - 1, L = 32 - __builtin_clz(sz), n = 1 << L;
    vector<C> in(n), out(n), root(n);
    for(int i = 0; i < A.size(); i++) in[i].real(A[i]);
    for(int i = 0; i < B.size(); i++) in[i].imag(B[i]);
    for(int i = 0; i < n / 2; i++)
        root[i + n/2] = polar(1.0, T_PI*(double)i/n);
    for(int i = n/2 - 1; i >= 0; i--)
        root[i] = root[i << 1];
    vector<int> rev(n);
    for(int i = 1; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (L - 1));
    fft(in, root, rev);
    for(int i = 0; i < n; i++) {
        C z = in[i], zc = in[-i & (n - 1)];
        out[i] = mul(zc, zc) - conj(mul(z, z));
    }
    fft(out, root, rev);
    vector<double> res(sz);
    for(int i = 0; i < sz; i++) res[i] = out[i].imag()/(4.0*n);
    return res;
}

const ll BASE = 100, DIGS = 2;
struct num {
    vector<ll> v;
    num(int x = 0) {
        v = {x};
    }
    num(vector<ll> _v) : v(_v) {};
    num(string s) {
        while(s.size() % DIGS)
            s = "0" + s;
        vector<ll> res;
        int x = s.size() - DIGS;
        while(x >= 0) {
            res.push_back(stoll(s.substr(x, DIGS)));
            x -= DIGS;
        }
        v = res;
    }
    num operator+ (const num &o) {
        int sz = max(v.size(), o.v.size());
        vector<ll> res(sz);
        for(int i = 0; i < sz; i++) {
            if(i < v.size()) res[i] += v[i];
            if(i < o.v.size()) res[i] += o.v[i];
        }
        for(int i = 0; i < sz - 1; i++) {
            if(res[i] >= BASE) {
                res[i] -= BASE;
                res[i + 1]++;
            }
        }
        if(res.back() >= BASE) {
            res.back() -= BASE;
            res.push_back(1);
        }
        return num(res);
    }
    num operator* (const num &o) {
        vector<double> A(v.size()), B(o.v.size());
        for(int i = 0; i < A.size(); i++) A[i] = v[i];
        for(int i = 0; i < B.size(); i++) B[i] = o.v[i];
        vector<double> P = conv(A, B);
        vector<ll> res(P.size());
        for(int i = 0; i < res.size(); i++)
            res[i] = (ll)round(P[i]);
        while(res.back() == 0)
            res.pop_back();
        for(int i = 0; i < res.size() - 1; i++) {
            if(res[i] >= BASE) {
                ll cr = res[i] / BASE;
                res[i] %= BASE;
                res[i + 1] += cr;
            }
        }
        if(res.back() >= BASE) {
            ll cr = res.back() / BASE;
            res.back() %= BASE;
            while(cr) {
                res.push_back(cr % BASE);
                cr /= BASE;
            }
        }
        return num(res);
    }
    num mul3() {
        int n = v.size();
        vector<ll> res(n);
        for(int i = 0; i < n; i++)
            res[i] = v[i]*3;
        for(int i = 0; i < n - 1; i++) {
            while(res[i] >= BASE) {
                res[i] -= BASE;
                res[i + 1]++;
            }
        }
        if(res.back() >= BASE) {
            res.push_back(0);
            while(res[n - 1] >= BASE) {
                res[n - 1] -= BASE;
                res[n]++;
            }
        }
        return num(res);
    }
    bool operator< (const num &o) const {
        if(o.v.size() < v.size()) return false;
        if(v.size() < o.v.size()) return true;
        for(int i = v.size() - 1; i >= 0; i--)
            if(v[i] != o.v[i]) return v[i] < o.v[i];
        return false;
    }
};

string to_string(num N) {
    int n = N.v.size();
    if(n == 1 && N.v[0] == 0)
        return "0";
    string rep;
    for(int i = n - 1; i >= 0; i--) {
        string s = to_string(N.v[i]);
        while(s.size() < DIGS)
            s = "0" + s;
        rep += s;
    }
    int pt = 0;
    while(rep[pt] == '0')
        pt++;
    rep = rep.substr(pt);
    return rep;
}

ostream& operator<< (ostream& out, num N) {
    out << to_string(N);
    return out;
}

num div2(num N) {
    if(N.v[0] % 2)
        N = N + num(1);
    int n = N.v.size();
    vector<ll> res(n), carry(n);
    for(int i = 0; i < n; i++) {
        res[i] = N.v[i] / 2;
        if(N.v[i] % 2 && i)
            carry[i - 1] = BASE/2;
    }
    num a(res), b(carry);
    a = a + b;
    while(a.v.back() == 0)
        a.v.pop_back();
    return a;
}

num operator^(num b, ll e) {
    num res(1);
    for(ll k = 1; k <= e; k <<= 1) {
        if(e & k)
            res = res * b;
        b = b * b;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if(s == "1") {
        cout << "1\n";
        return 0;
    }
    num N(s);
    ll ans = 1e18;
    ll lg = ((to_string(N).size()-1) * (log(10.0)/log(3.0)));
    lg = max(lg - 2, 0LL);
    num M = (num(3))^lg;
    for(int i = 0; i < 3; i++) {    
        ll can = 2*i + 3*lg;
        num T = M;
        while(T < N) {
            can += 3;
            T = T.mul3();
        }
        ans = min(ans, can);
        N = div2(N);
    }
    cout << ans << endl;
}