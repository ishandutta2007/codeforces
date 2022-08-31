#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 10004;
int a[MX];
int n;

void solve() {
    if (a[n] == 0) {
        REP(i, n+1) cout << (i+1) << " ";
        return;
    }
    int p = -1;
    for (int i = n - 1; i > 0; i--)
        if (a[i] == 0) {
            p = i; break;
        }
    // cout << "p = " << p << endl;
    if (p == -1) {
        // cout << "-1"; return; 
        cout << (n+1) << " ";    
        REP(i, n) cout << (i+1) << " ";
        return;
    }
    REP(i, p) cout << (i+1) << " ";
    cout << (n+1) << " ";
    for (int i = p+1; i <= n; i++) cout << i << " ";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i+1];
        }
        solve();
        cout << "\n";
    }
    
    return 0;
}