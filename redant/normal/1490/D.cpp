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

const int MX = 105;
int a[MX], d[MX];
int n;

void f(int l, int r, int dp) {
    // cout << l << " : " << r << ", dp = " << dp << "\n";
    if (l >= r) return;
    auto mxit = max_element(a+l, a+r);
    // cout << "mx = " << *mxit << " = " << dp << "\n";
    d[*mxit] = dp;
    f(l, mxit-a, dp+1);
    f(mxit+1-a, r, dp+1);
}

void solve() {
    f(0, n, 0);
    REP(i, n) cout << d[a[i]] << " ";
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        solve();
    }
    
    return 0;
}