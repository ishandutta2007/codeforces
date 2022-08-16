#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 305;
int a[MX][MX];
int n, m;

void solve() {
    REP(i, n) {
        REP(j, m) {
            if (((i+j)&1) != (a[i][j]&1)) ++a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            REP(j, m)
                cin>>a[i][j];
        }
        solve();
    }
    
    return 0;
}