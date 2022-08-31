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

int k, n, a, b;

bool can(int r) {
    assert(r >= 0);
    if (r == 0) {
        if (k <= b) return false;
        return ((k - 1) / b) >= n;
    }
    LL kk = k - 1ll * (r - 1) * a;
    if (kk <= a) return false;
    kk -= a;
    if (kk > b) {
        r += (kk - 1) / b;
    }
    return r >= n;
}

int solve() {
    if (can(n)) return n;
    int lo = -1, hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (can(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>k>>n>>a>>b;
        cout<<solve()<<"\n";
    }
    
    return 0;
}