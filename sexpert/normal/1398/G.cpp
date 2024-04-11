#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

typedef complex<double> C;
typedef vector<double> vd;
typedef vector<int> vi;

const double TPI = 2.0 * acos(-1);

void fft(vector<C> &v) {
    int n = sz(v), lg = __lg(n);
    vector<C> rt(n);
    vi rev(n);
    for(int i = 0; i < n / 2; i++)
        rt[i + n / 2] = polar(1.0, TPI * (double)i / (double) n);
    for(int i = n/2 - 1; i >= 0; i--)
        rt[i] = rt[2*i];
    for(int i = 0; i < n; i++)
        rev[i] = (rev[i / 2] | (i & 1) << lg) / 2;
    for(int i = 0; i < n; i++)
        if(i < rev[i]) swap(v[i], v[rev[i]]);
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                C z = v[i + j + k] * rt[j + k];
                v[i + j + k] = v[i + j] - z;
                v[i + j] += z;
            }
        }
    }
}

vd conv(const vd& a, const vd& b) {
    int L = sz(a) + sz(b) - 1, n = 1 << (__lg(L) + 1);
    vector<C> A(n), B(n);
    for(int i = 0; i < sz(a); i++)
        A[i].real(a[i]);
    for(int i = 0; i < sz(b); i++)
        B[i].real(b[i]);
    fft(A);
    fft(B);
    for(int i = 0; i < n; i++)
        A[i] *= B[i];
    reverse(A.begin() + 1, A.end());
    fft(A);
    vd res(L);
    for(int i = 0; i < L; i++)
        res[i] = A[i].real();
    return res;
}

const int BIG = 1e6 + 10;
int good[BIG], ans[BIG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    vd A(x + 1), B(x + 1);

    for(int i = 0; i <= n; i++) {
        int k;
        cin >> k;
        A[k]++;
        B[x - k]++;
    }

    vd C = conv(A, B);
    for(int i = x; i < C.size(); i++) {
        if(C[i] > 0.5)
            good[i - x] = 1;
    }
    /*for(int i = 1; i < BIG; i++) {
        if(good[i])
            cout << i << " ";
    }
    cout << '\n';*/
    int q;
    cin >> q;
    while(q--) {
        int L;
        cin >> L;
        if(ans[L] != 0) {
            cout << ans[L] << '\n';
            continue;
        }
        L /= 2;
        vector<int> divs;
        for(int d = 1; d * d <= L; d++) {
            if(L % d == 0) {
                divs.push_back(d);
                if(L/d > d)
                    divs.push_back(L / d);
            }
        }
        int res = -1;
        for(auto d : divs) {
            if(d > y && good[d - y])
                res = max(res, d);
        }
        ans[2 * L] = 2 * res;
        if(ans[2 * L] == -2)
            ans[2 * L] = -1;
        cout << ans[2 * L] << " ";
    }
    cout << '\n';
}