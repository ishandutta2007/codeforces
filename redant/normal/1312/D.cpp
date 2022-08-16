#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// = Mod pow ==

const int SZ = 200005;
const LL mod = 998244353;

int madd(int a, int b) {
    a = a + b;
    while (a < 0) a += mod;
    while (a >= mod) a -= mod;
    return a;
}

int mmul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int mpow(int a, int n) {
    int r = 1;
    for(; n; n >>= 1) {
        if (n&1) r = mmul(r, a);
        a = mmul(a, a);
    }
    return r;
}

int minv(int a) {
    return mpow(a, mod-2);
}

int mdiv(int a, int b) {
    return mmul(a, minv(b));
}

int fac[SZ];

void nfinit() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < SZ; i++) {
        fac[i] = mmul(i, fac[i-1]);
    }
}

int nck(int n, int k) {
    if (n < k) return 0;
    if (k == 0 || n == k) return 1;
    if (fac[0] == 0) nfinit();
    return mdiv(fac[n], mmul(fac[n-k], fac[k]));
}

// ------------

int main() {
    setIO();
    int n, m;
    cin>>n>>m;
    LL r = 0;
    if (n > 2) {
        r = mmul(mmul(nck(m, n-1), n-2), mpow(2, n-3));
    }
    cout<<r<<endl;    
    return 0;
}