#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, a, b;

LL solve() {
    LL r = (n % 2) * a;
    n -= n % 2;
    return r + min(n * a, n / 2 * b);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        cout<<solve()<<"\n";
    }
    
    return 0;
}