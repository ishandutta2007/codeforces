#include <bits/stdc++.h>
using namespace std;

const double T_PI = 2.0 * acos(-1);
typedef complex<double> C;

C mul(const C &x, const C &y) {
    double rx = x.real(), ix = x.imag(), ry = y.real(), iy = y.imag();
    return C(rx * ry - ix * iy, rx * iy + ix * ry);
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
                f[i + j] += z;
            }
        }
    }
}

vector<double> conv(vector<double> &A, vector<double> &B) {
    int sz = A.size() + B.size() - 1, L = 32 - __builtin_clz(sz), n = 1 << L;
    vector<C> in(n), out(n), root(n);
    for(int i = 0; i < A.size(); i++)
        in[i].real(A[i]);
    for(int i = 0; i < B.size(); i++)
        in[i].imag(B[i]);
    for(int i = 0; i < n / 2; i++)
        root[i + n/2] = polar(1.0, T_PI*(double)i/n);
    for(int i = n / 2 - 1; i >= 0; i--)
        root[i] = root[2*i];
    vector<int> rev(n);
    for(int i = 1; i < n; i++)
        rev[i] = (rev[i / 2] / 2) + ((i & 1) << (L - 1));
    fft(in, root, rev);
    for(int i = 0; i < n; i++) {
        C z = in[i], zc = in[-i & (n - 1)];
        out[i] = mul(zc, zc) - conj(mul(z, z));
    }
    fft(out, root, rev);
    vector<double> res(sz);
    for(int i = 0; i < sz; i++)
        res[i] = out[i].imag()/(4.0*n);
    for(auto &d : res)
        d = min(floor(d + 0.5), 1.0);
    while(fabs(res.back() < 1e-9))
        res.pop_back();
    return res;
}

vector<double> bpow(vector<double> f, int e) {
    vector<double> res = {1};
    for(int k = 1; k <= e; k *= 2) {
        if(k & e) res = conv(res, f);
        f = conv(f, f);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<double> f(1001);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x] = 1;
    }
    while(fabs(f.back()) < 1e-9)
        f.pop_back();
    vector<double> res = bpow(f, k);
    for(int i = 0; i < res.size(); i++)
        if(res[i] > 0.5)
            cout << i << " ";
    cout << '\n';
}