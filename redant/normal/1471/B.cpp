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

const int MX = 100005;
LL a[MX];
LL ps[MX];
int n, x;

LL solve() {
    REP(i, n) ps[i+1] = a[i+1] + ps[i];
    LL r = ps[n];
    int mn = a[1];
    REP(i, n) {
        int k = 0;
        for (int m = a[i+1]; m % x == 0; m /= x)
            ++k;
        if (k < mn) {
            r = (k + 1) * ps[n] + ps[i];
            mn = k; 
        }
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>x;
        REP(i, n) {
            cin>>a[i+1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}