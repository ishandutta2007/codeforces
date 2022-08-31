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

LL gcd(LL a, LL b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

const int MX = 200005;
LL a[MX], b[MX];
int n, m;

LL solve() {
    sort(a, a+n);
    LL ga = 0;
    REP(i, n-1) ga = gcd(a[i+1]-a[i], ga);
    REP(i, m) {
        cout << gcd(b[i] + a[0], ga) << " ";
    }
    cout << "\n";
}

int main() {
    setIO();
    cin>>n>>m;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    solve();
    return 0;
}