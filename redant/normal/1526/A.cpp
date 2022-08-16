#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 55;
int a[MX];
int n;

void solve() {
    sort(a, a+2*n);
    REP(i, n) {
        cout << a[i] << " " << a[n+i] << " ";
    }
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, 2*n) {
            cin>>a[i];
        }
        solve();
    }
    
    return 0;
}