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

const int MX = 100005;
LL a[MX];
LL d[MX];
int n, q;
LL k;

LL solve(int l, int r) {
    if (l == r) return k - 1;
    LL res = 0;
    res += a[l+1] - 2;
    res += k - a[r-1] - 1;
    res += d[r-1] - d[l];
    return res;
}

int main() {
    setIO();
    cin>>n>>q>>k;
    REP(i, n) {
        cin>>a[i+1];
    }
    REP(i, n - 2) {
        d[i+2] = d[i+1] + a[i+3] - a[i+1] - 2;
    }
    REP(i, q) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << "\n";
    }
    
    return 0;
}