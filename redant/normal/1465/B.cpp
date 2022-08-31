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

bool ok(LL x) {
    LL xx = x;
    while (x) {
        int d = x % 10;
        if (d && xx % d != 0)
            return false;
        x /= 10;
    }
    return true;
}

LL solve(LL n) {
    while (!ok(n)) ++n;
    return n;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        cout<<solve(n)<<"\n";
    }
    
    return 0;
}