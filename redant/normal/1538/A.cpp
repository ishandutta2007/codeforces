#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 111;
int a[MX];
int n;

int solve() {
    int b[2][2];
    REP(i, n) {
        if (a[i] == 1 || a[i] == n) {
            b[a[i] == 1][0] = 1 + i;
            b[a[i] == 1][1] = n - i;
        }
    }
    // REP(i, 2) cout << b[i][0] << " " << b[i][1] << "\n";
    int r = n;
    r = min(r, max(b[0][0], b[1][0]));
    r = min(r, max(b[0][1], b[1][1]));
    r = min(r, b[0][0] + b[1][1]);
    r = min(r, b[0][1] + b[1][0]);
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}