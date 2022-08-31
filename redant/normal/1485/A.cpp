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

LL a, b;

LL get(LL y) {
    LL r = 0;
    for (LL x = a; x; x/=y, ++r);
    return r;
}

LL solve() {
    LL r = 1e9, k = 0;
    if (b == 1) {
        ++k;
        b = 2;
    }
    for (;k<50;k++) {
        r = min(r, k + get(b));
        ++b;
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>a>>b;
        cout<<solve()<<"\n";
    }
    
    return 0;
}