#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 1005;
const int mod = 1e9 + 7;

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

const int MX = 1005;
int a[MX];
int n, k;
int f[MX];

int solve() {
    REP(i, n+1) f[i] = 0;
    REP(i, n) f[a[i]]++;
    for (int i = n; ; i--) {
        if (f[i] >= k)
            return nck(f[i], k); 
        k -= f[i];
    }
    return 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}