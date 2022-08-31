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
int a[MX];
int n, k;

int solve() {
    int mn = 1, mx = 2e8;
    REP(i, n) {
        int x = max(1, a[i] - k);
        int y = a[i] + k;
        mn = max(mn, x);
        mx = min(mx, y);
    }
    return mx < mn ? -1 : mx; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}