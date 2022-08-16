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

LL solve() {
    LL r = 0;
    LL p10 = 10;
    while (p10 - 1 <= b) {
        r += a;
        p10 *= 10;
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