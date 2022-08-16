#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const LL mod = 1e9+7;
const int SZ = 100005;

LL a[SZ], b[SZ], p[SZ];
string s;
int n;

LL solve() {
    // precalc
    p[0] = 1;
    REP(i, n) {
        p[i+1] = (p[i] * 10) % mod;
    }
    REP(i, n+1) {
        a[i] = (i * 1ll * (i+1)) / 2 % mod;
    }
    b[0] = 1;
    REP(i, n) {
        b[i+1] = (b[i] + (i+2) * p[i+1] % mod) % mod;
    }

    LL r = 0;
    REP(i, n) {
        LL d = s[i] - '0';
        LL f = 0;
        if (i > 0) f = (f + a[i] * p[n-1-i] % mod) % mod;
        if (i < n-1) f = (f + b[n-i-2]) % mod;
        r = (r + f * d % mod) % mod;
    }
    return r;
}

int main() {
    setIO();
    cin>>s;
    n=s.length();
    cout << solve()<< endl;
    return 0;
}