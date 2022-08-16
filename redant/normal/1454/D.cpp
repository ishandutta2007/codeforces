#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, N;
LL mx, mxc;

void check(LL v) {
    if (v <= 1) return;
    if (n % v != 0) return;
    int c = 0;
    while (n  % v == 0) {
        ++c;
        n /= v;
    }

    if (c > mxc) {
        mx = v;
        mxc = c;
    }
}

void solve() {
    N = n;
    mx = n, mxc = 1;
    for (LL i = 1; i * i <= n; i++) {
        check(i);
    }
    check(n);
    n = N;
    cout << mxc << "\n";
    REP(i, mxc - 1) {
        cout << mx << " ";
        n /= mx;
    }
    if (n > 1) {
        cout << n << "\n";
    }
    return;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        solve();
    }
    
    return 0;
}