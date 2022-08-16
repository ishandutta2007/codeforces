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

const int MX = 200005;
int a[MX];
int n, m, k;

const int mod = 1e9+7;

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

int fac[MX];

void nfinit() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MX; i++) {
        fac[i] = mmul(i, fac[i-1]);
    }
}

int nck(int n, int k) {
    if (n < k) return 0;
    if (k == 0 || n == k) return 1;
    if (fac[0] == 0) nfinit();
    return mdiv(fac[n], mmul(fac[n-k], fac[k]));
}

int solve() {
    sort(a, a+n);
    int r = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i);
        while (j+1 < n && a[j+1] - a[i] <= k)
            ++j;
        int total = j - i + 1;
        int icount = 1;
        while (i+1 < n && a[i+1] == a[i]) {
            ++i;
            ++icount;
        }
        r = madd(r, nck(total, m));
        r = madd(r, -nck(total - icount, m));
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}