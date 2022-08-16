#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 305;
int a[MX];
int n, m;

int solve() {
    LL r = 0;
    FOR(i, 1, n+1) {
        r += a[i];
        if (r>m) return 0;
    }
    return r==m;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i+1];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}