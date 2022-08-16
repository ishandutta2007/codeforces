#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int f() {
    int n; cin>>n;
    int mx = 0, s = 0;
    REP(i, n) {
        int x; cin >> x;
        s += x;
        mx = max(mx, s);
    }
    return mx;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cout<<(f() + f())<<"\n";
    }
    
    return 0;
}