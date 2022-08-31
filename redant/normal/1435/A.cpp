#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 305;
int a[MX];
int n;

void solve() {
    for (int i = 0; i < n; i += 2) {
        cout << -a[i+1] << " " << a[i] << " ";
    }
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