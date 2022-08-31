#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int l, r;

int solve() {
    int b = (r + 1) / 2;
    if (b >= l) return b - 1;
    return r % l;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>l>>r;
        cout<<solve()<<"\n";
    }
    
    return 0;
}