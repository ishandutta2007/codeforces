#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int x, y;

int solve() {
    int r = 2 * min(x, y);
    x = x + y - r;
    r += x == 0 ? 0 : (x - 1) * 2 + 1;
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>x>>y;
        cout<<solve()<<"\n";
    }
    
    return 0;
}