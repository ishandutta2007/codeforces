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

int pre[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int ans = a.size() - b.size() + 1, ct = 0;
    reverse(a.begin(), a.end());
    vector<double> P, Q;
    for(int i = 0; i < a.size(); i++) {
        P.push_back(a[i] -'0');
        pre[i] = (a[i] - '0') + (i ? pre[i - 1] : 0);
    }
    for(auto c : b) {
        Q.push_back(c - '0');
        ct += (c - '0');
    }
    auto R = conv(P, Q);
    for(int i = b.size() - 1; i < a.size(); i++) {
        int s = ct + pre[i] - (i >= b.size() ? pre[i - b.size()] : 0);
        if((s - 2*(int)round(R[i])) & 1) ans--;
    }
    cout << ans << endl;
}