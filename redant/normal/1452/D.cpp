#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

const int mod = 998244353;

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

int solve() {
    int prev[2] = {mdiv(1, 2), 0};
    int p = 1, cnum, cden, c;
    REP(i, n) {
        c = prev[1-p];
        prev[p] = madd(prev[p], c);
        REP(j, 2) {
            prev[j] = mdiv(prev[j], 2);
        }
        p = 1 - p;
    }
    return c;
}

int main() {
    setIO();
    cin>>n;
    cout<<solve()<<"\n";   
    return 0;
}