#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 105;
int a[SZ];
int n, m, k, x, y;

int solve() {
    x = -1;
    int d = 0;
    REP(i, n) {
        if (a[i] != x) d++;
        x = a[i];
    }
    if (k==1) return d==1?1:-1;
    d = max(0, d - k);
    return 1 + (d + k - 2) / (k - 1);
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