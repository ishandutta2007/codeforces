#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 1005;
int a[MX];
int n;

void solve() {
    cout << 3 * n << "\n";
    for (int i = 1, j = 2; i < n; i += 2, j += 2) {
        REP(k, 2) {
            cout << "2 " << i << " " << j << "\n";
            cout << "1 " << i << " " << j << "\n";
            cout << "1 " << i << " " << j << "\n";
        }
    }
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