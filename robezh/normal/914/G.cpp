#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2 * (1 << 17) + 5, mod = (int)1e9 + 7, inv2 = (int)5e8 + 4, M = (int)5e4 + 50;

ll add(ll a, ll b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
    return a;
}

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll mul(ll a, ll b) {
    return (a * b % mod);
}

int n, m;
ll fib[N];
ll s1[N], s2[N], s3[N];
ll freq[N];
ll res[N];

struct FWT {
    int N;
    void FWTor(ll *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k + mid] = add(a[j + k], a[j + k + mid]);
                    else a[j + k + mid] = add(a[j + k + mid], -a[j + k]);
    }
    void FWTand(ll *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k] = add(a[j + k], a[j + k + mid]);
                    else a[j + k] = add(a[j + k], -a[j + k + mid]);
    }
    void FWTxor(ll *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++) {
                    ll x = a[j + k], y = a[j + k + mid];
                    if(opt == 1) a[j + k] = add(x, y), a[j + k + mid] = add(x, -y);
                    else a[j + k] = mul(add(x, y), inv2), a[j + k + mid] = mul(add(x, -y), inv2);
                }

    }
} fwt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i < N; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; freq[x]++;
    }
    n = fwt.N = (1 << 17);
    for(int i = 0; i < n; i++) {
        for(int j = i;; j = (j - 1) & i) {
            s1[i] = add(s1[i], mul(freq[i ^ j], freq[j]));
            if(j == 0) break;
        }
    }
    for(int i = 0; i < n; i++) s2[i] = freq[i], s3[i] = freq[i];
    fwt.FWTxor(s3, 1);
    for(int i = 0; i < n; i++) s3[i] = mul(s3[i], s3[i]);
    fwt.FWTxor(s3, -1);
    for(int i = 0; i < n; i++) {
        s1[i] = mul(s1[i], fib[i]);
        s2[i] = mul(s2[i], fib[i]);
        s3[i] = mul(s3[i], fib[i]);
    }
    fwt.FWTand(s1, 1);
    fwt.FWTand(s2, 1);
    fwt.FWTand(s3, 1);
    for(int i = 0; i < n; i++) res[i] = mul(s1[i], mul(s2[i], s3[i]));
    fwt.FWTand(res, -1);

    ll fres = 0;
    for(int i = 0; i < 17; i++) {
        fres = add(fres, res[1 << i]);
    }
    cout << fres << endl;

}